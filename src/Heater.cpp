#include "Heater.h"

int Heater::heatupWatertank(int TargettemperatureInDegreesCelsius) {
	if (measureWatertemperature() < TargettemperatureInDegreesCelsius) {
		activateHeater();
		// Measure temperature and compare to target temperature
		do {
			measureWatertemperature();
		} while (mWatertemperature < TargettemperatureInDegreesCelsius);
		deactivateHeater();
	}
	return (mWatertemperature);
}

int Heater::measureWatertemperature() {
	mWatertemperature++;  // Emulate heating
	return (mWatertemperature);
}

bool Heater::activateHeater() {
	// Set corresponding Bit on I/O-Card 

	// Reset water tempetrature to ambient temperature for emulation
	mWatertemperature = AMBIENTTEMPERATURE;

	return (true); // No errors expected
}

bool Heater::deactivateHeater() {
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

Heater::Heater() {
	mWatertemperature = AMBIENTTEMPERATURE;
}

Heater::~Heater() {
}
