/* Copyright 2007-2015 QReal Research Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#include "conditionsFactory.h"

#include <QtCore/QSharedPointer>

#include <qrutils/mathUtils/geometry.h>

#include "event.h"
#include "twoDModel/engine/model/robotModel.h"
#include "src/engine/items/regions/regionItem.h"

using namespace twoDModel::constraints::details;
using namespace kitBase;

ConditionsFactory::ConditionsFactory(Events &events
		, const Objects &objects
		, StatusReporter &status)
	: mEvents(events)
	, mObjects(objects)
	, mStatus(status)
{
}

Condition ConditionsFactory::constant(bool value) const
{
	return [value]() { return value; };
}

Condition ConditionsFactory::combined(const QList<Condition> &conditions, Glue glue) const
{
	return [conditions, glue]() {
		for (const Condition &condition : conditions) {
			const bool value = condition();

			if (glue == Glue::And && !value) {
				return false;
			}

			if (glue == Glue::Or && value) {
				return true;
			}
		}

		return glue == Glue::And;
	};
}

Condition ConditionsFactory::negation(const Condition &condition) const
{
	return [condition]() { return !condition(); };
}

Condition ConditionsFactory::equals(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() == rightValue(); };
}

Condition ConditionsFactory::notEqual(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() != rightValue(); };
}

Condition ConditionsFactory::greater(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() > rightValue(); };
}

Condition ConditionsFactory::less(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() < rightValue(); };
}

Condition ConditionsFactory::notGreater(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() <= rightValue(); };
}

Condition ConditionsFactory::notLess(const Value &leftValue, const Value &rightValue) const
{
	return [leftValue, rightValue]() { return leftValue() >= rightValue(); };
}

Condition ConditionsFactory::inside(const QString &objectId, const QString &regionId, const QString &objectPoint) const
{
	return [this, objectId, regionId, objectPoint]() {
		if (!mObjects.contains(objectId)) {
			reportError(QObject::tr("No such object: %1").arg(objectId));
			return false;
		}

		if (!mObjects.contains(regionId)) {
			reportError(QObject::tr("No such region: %1").arg(regionId));
			return false;
		}

		QObject * const object = mObjects[objectId];
		items::RegionItem * const region = dynamic_cast<items::RegionItem *>(mObjects[regionId]);

		if (!region) {
			reportError(QObject::tr("%1 is not a region").arg(regionId));
			return false;
		}

		if (QGraphicsObject * const graphicsObject = dynamic_cast<QGraphicsObject *>(object)) {
			if (objectPoint == "all") {
				return region->mapToScene(region->shape()).contains(
						graphicsObject->mapToScene(graphicsObject->shape()));
			} else if (objectPoint == "any") {
				return region->mapToScene(region->shape()).intersects(
						graphicsObject->mapToScene(graphicsObject->shape()));
			}
			return region->containsItem(graphicsObject);
		}

		if (model::RobotModel * const robotModel = dynamic_cast<model::RobotModel *>(object)) {
			if (objectPoint == "all") {
				return region->mapToScene(region->shape()).contains(robotModel->robotBoundingPath(false));
			} else if (objectPoint == "any") {
				return region->mapToScene(region->shape()).intersects(robotModel->robotBoundingPath(false));
			}
			return region->containsPoint(robotModel->robotCenter());
		}

		if (kitBase::robotModel::robotParts::Device * const device
				= dynamic_cast<kitBase::robotModel::robotParts::Device *>(object))
		{
			const QStringList parts = objectId.split('.');
			if (objectId.isEmpty()) {
				return false;
			}

			const QString robotId = parts[0];
			if (!mObjects.contains(robotId)) {
				return false;
			}

			if (model::RobotModel * const robotModel = dynamic_cast<model::RobotModel *>(mObjects[robotId])) {
				auto deviceShape = robotModel->robotsTransform().map(
						robotModel->sensorBoundingPath(device->port()));
				if (objectPoint == "all") {
					return region->mapToScene(region->shape()).contains(
							deviceShape.isEmpty() ? robotModel->robotBoundingPath(false) : deviceShape);
				} else if (objectPoint == "any") {
					return region->mapToScene(region->shape()).intersects(
							deviceShape.isEmpty() ? robotModel->robotBoundingPath(false) : deviceShape);
				}
				return region->containsPoint(
						robotModel->robotsTransform().map(robotModel->configuration().position(device->port())));
			}

			return false;
		}

		reportError(QObject::tr("%1 has incorrect type for matching it with region").arg(objectId));
		return false;
	};
}

Condition ConditionsFactory::settedUp(const QString &eventId) const
{
	return [eventId, this]() {
		if (!mEvents.contains(eventId)) {
			reportError(QObject::tr("No such event: %1").arg(eventId));
			return false;
		}

		return mEvents[eventId]->isAlive();
	};
}

Condition ConditionsFactory::dropped(const QString &eventId) const
{
	return [eventId, this]() {
		if (!mEvents.contains(eventId)) {
			reportError(QObject::tr("No such event: %1").arg(eventId));
			return true;
		}

		return !mEvents[eventId]->isAlive();
	};
}

Condition ConditionsFactory::timerCondition(int timeout, bool forceDrop, const Value &timestamp, Event &event) const
{
	// We must remember somewhere timestamp when parent event was setted up.
	// We can do this in the event itself, by why? There will be no need in it except here, so storing it in heap...
	QSharedPointer<qint64> lastSetUpTimestamp(new qint64(-1));

	QObject::connect(&event, &Event::settedUp, [lastSetUpTimestamp, timestamp]() {
		*lastSetUpTimestamp = timestamp().toLongLong();
	});

	return [timeout, forceDrop, timestamp, &event, lastSetUpTimestamp]() {
		const bool timeElapsed = *lastSetUpTimestamp >= 0 && timestamp().toLongLong() - *lastSetUpTimestamp >= timeout;
		if (timeElapsed && forceDrop) {
			// Someone may think that dropping here will not let the event fire even if all conditions are satisfied.
			// But we get into this lambda after checking this event`s aliveness, so it will fire (but after drop).
			event.drop();
		}

		return timeElapsed;
	};
}

Condition ConditionsFactory::usingCondition(const Condition &returns, const Trigger &trigger) const
{
	return [returns, trigger]() {
		trigger();
		return returns();
	};
}

void ConditionsFactory::reportError(const QString &message) const
{
	emit mStatus.checkerError(message);
}
