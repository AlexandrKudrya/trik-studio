#include "colorSensor.h"

using namespace trikKitInterpreter::robotModel::real::parts;
using namespace interpreterBase::robotModel;

ColorSensor::ColorSensor(const DeviceInfo &info, const PortInfo &port, utils::TcpRobotCommunicator &robotCommunicator)
	: robotModel::parts::TrikColorSensor(info, port)
	, mRobotCommunicator(robotCommunicator)
{
}

void ColorSensor::init()
{
}

void ColorSensor::read()
{
	emit newData({0, 0, 0});
}
