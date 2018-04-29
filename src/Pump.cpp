#include "Pump.h"
Pump::Pump() {
	mWatervolume = measureWatervolume(); // Accurate volume on first call
	mWatervolume = measureWatervolume(); // Accurate volume difference on second call
}

Pump::~Pump() {

}

bool Pump::activatePump() {
	// Set corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Pump::deactivatePump() {
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Pump::openWatervalve() {
	// Set corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Pump::closeWatervalve() {
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

float Pump::pumpWater(float TargetvolumeInMl) {
	int T = 5; // Scan time in ms
			   // nominal inflow at 100ml/s
	float pumpedVolume;
	float startVolume = measureWatervolume();
	float MinDeltaV = (float)((1 - EPSREL)*T*0.1); // 90% of nominal pumped volume in T
	activatePump();
	// Determine pumped volume and compare with target volume
	do {
		Sleep(T); // Waiting for T ms => T*0,1ml nominal
				  // Calculate pumped volume since start of measurement
		pumpedVolume = measureWatervolume() - startVolume;
		// Calculate pumped volume sicne last time of measurement
		if (mActualDeltaV < MinDeltaV) {
			break; // If pumping result is wrong: cancel process
		}
	} while (pumpedVolume < TargetvolumeInMl);
	deactivatePump();
	return (pumpedVolume);
}

float Pump::measureWatervolume() {
	float lastVolume;
	// Save last value
	lastVolume = mWatervolume;
	// Measure
	mWatervolume++;  // Emulate volume flow rate
					 // Calculate ActualDeltaV
	mActualDeltaV = mWatervolume - lastVolume;
	return (mWatervolume);
}
