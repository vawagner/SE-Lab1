#ifndef HEATER_H
#define HEATER_H
#include "stdafx.h"

class Heater {


public:
	int heatupWatertank(int TargettemperatureInDegreesCelsius);

	int measureWatertemperature();

	bool activateHeater();

	bool deactivateHeater();

	Heater();

	~Heater();

private:
	/**
	 * watervolume as difference between the two latest times of measurement, value in ml
	 */
	int mWatertemperature;
};

#endif
