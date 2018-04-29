#ifndef PUMP_H
#define PUMP_H
#include "stdafx.h"

class Pump {


public:
	Pump();
	~Pump();
	bool activatePump();

	bool deactivatePump();

	bool openWatervalve();

	bool closeWatervalve();

	float pumpWater(float TargetvolumeInMl);

	/**
	 * Value in �C
	 */
	float measureWatervolume();

private:
	/**
	 * Value in �C
	 */
	float mWatervolume;
	/**
	 * latest count of the water meter, value in ml
	 */
	float mActualDeltaV;
};

#endif
