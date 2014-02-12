#include "interpreterBase/robotModel/commonRobotModel.h"

#include <qrkernel/exception/exception.h>

#include "interpreterBase/robotModel/robotParts/touchSensor.h"

using namespace interpreterBase::robotModel;

CommonRobotModel::CommonRobotModel()
	: mBrick(new robotParts::Brick())
	, mDisplay(new robotParts::Display())
{
	connect(&mConfiguration, &Configuration::allDevicesConfigured
			, this, &CommonRobotModel::allDevicesConfigured);
}

CommonRobotModel::~CommonRobotModel()
{
	stopRobot();
}

void CommonRobotModel::init()
{
	mConfiguration.lockConfiguring();
	rereadSettings();
	configureKnownDevices();
}

void CommonRobotModel::connectToRobot()
{
	mConfiguration.configure();
	doConnectToRobot();
}

void CommonRobotModel::stopRobot()
{
}

void CommonRobotModel::disconnectFromRobot()
{
	emit disconnected();
}

ConfigurationInterface &CommonRobotModel::mutableConfiguration()
{
	return mConfiguration;
}

ConfigurationInterface const &CommonRobotModel::configuration() const
{
	return mConfiguration;
}

robotParts::Brick &CommonRobotModel::brick()
{
	return *mBrick;
}

robotParts::Display &CommonRobotModel::display()
{
	return *mDisplay;
}

QList<PortInfo> CommonRobotModel::availablePorts() const
{
	return mAllowedConnections.keys();
}

QList<PortInfo> CommonRobotModel::configurablePorts() const
{
	return availablePorts();
}

QList<PluggableDeviceInfo> CommonRobotModel::allowedDevices(PortInfo const &port) const
{
	return mAllowedConnections[port];
}

void CommonRobotModel::configureDevice(PortInfo const &port, PluggableDeviceInfo const &deviceInfo)
{
	robotParts::PluggableDevice *device = createDevice(port, deviceInfo);
	if (device) {
		mConfiguration.configureDevice(device);
	}
	/// @todo Handle error
}

QList<PluggableDeviceInfo> CommonRobotModel::convertibleBases() const
{
	return {};
}

void CommonRobotModel::rereadSettings()
{
}

void CommonRobotModel::setBrick(robotParts::Brick *brick)
{
	mBrick.reset(brick);
}

void CommonRobotModel::setDisplay(robotParts::Display *display)
{
	mDisplay.reset(display);
}

void CommonRobotModel::addAllowedConnection(PortInfo const &port, QList<PluggableDeviceInfo> const &devices)
{
	mAllowedConnections[port].append(devices);
}

void CommonRobotModel::onConnected()
{
	emit connected(true);
	mConfiguration.unlockConfiguring();
}

void CommonRobotModel::doConnectToRobot()
{
	onConnected();
}

void CommonRobotModel::configureKnownDevices()
{
}

robotParts::PluggableDevice * CommonRobotModel::createDevice(
		PortInfo const &port, PluggableDeviceInfo const &deviceInfo)
{
	Q_UNUSED(port);
	Q_UNUSED(deviceInfo);

	/// @todo Handle error?
	return nullptr;
}
