#ifndef BREWINGSYSTEM_H
#define BREWINGSYSTEM_H

/**
 * Filename   : Brewingssystem.h
 *    Description: 
 * --------------------------------------------------------------------------------
 */
class Brewingsystem {

private:
	/**
	 * Value in �C
	 */
	float mWatervolume;
	/**
	 * latest count of the water meter, value in ml
	 */
	float mActualDeltaV;
	/**
	 * watervolume as difference between the two latest times of measurement, value in ml
	 */
	int mWatertemperature;

public:
	/**
	 * possible status: ready, heatup, pump, error
	 */
	Brewingsystem(void unnamed_1);

	~Brewingsystem(void unnamed_1);

	bool activateHeater();

	bool deactivateHeater();

	bool activatePump();

	bool deactivatePump();

	bool openWatervalve();

	bool closeWatervalve();

	float pumpWater(float TargetvolumeInMl);

	float brewCoffee(float TargetvolumeInMl);

	int measureWatertemperature();

	/**
	 * Value in �C
	 */
	float measureWatervolume();

	int heatupWatertank(int TargettemperatureInDegreesCelsius);
};

#endif
