#pragma once

#include "abstractRecognizer.h"
#include "geometricForms.h"

namespace qReal {
namespace gestures {

class NearestPosGridGesturesManager : public GesturesRecognizer<qreal *>
{
public:
	NearestPosGridGesturesManager();
	~NearestPosGridGesturesManager();
	qreal getMaxDistance(QString const &);
	bool isMultistroke();
	qreal getDistance(qreal * const & key1, qreal * const &key2);

	qreal getDistance(QString const &item) override
	{
		const auto key = mGestures[item];
		return getDistance(mKey, key);
	}

	qreal *getKey(PathVector const &path);
};

}
}
