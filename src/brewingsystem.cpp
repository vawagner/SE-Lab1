
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Brewingsystem.cpp
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"


#include "stdafx.h"
#include "brewingsystem.h"

Brewingsystem::Brewingsystem (void ){
	mWatervolume = measureWatervolume(); // Accurate volume on first call
	mWatervolume = measureWatervolume(); // Accurate volume difference on second call
	mWatertemperature = AMBIENTTEMPERATURE;
}

Brewingsystem::~Brewingsystem (void ){

}

bool Brewingsystem::activateHeater ()
{
	// Set corresponding Bit on I/O-Card 

	// Reset water tempetrature to ambient temperature for emulation
	mWatertemperature = AMBIENTTEMPERATURE;

	return (true); // No errors expected
}

bool Brewingsystem::deactivateHeater ()
{
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Brewingsystem::activatePump ()
{
	// Set corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Brewingsystem::deactivatePump ()
{
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Brewingsystem::openWatervalve ()
{
	// Set corresponding Bit on I/O-Card
	return (true); // No errors expected
}

bool Brewingsystem::closeWatervalve ()
{
	// Reset corresponding Bit on I/O-Card
	return (true); // No errors expected
}

float Brewingsystem::pumpWater (float TargetvolumeInMl)
{
	int T = 5; // Scan time in ms
	// nominal inflow at 100ml/s
	float pumpedVolume;
	float startVolume = measureWatervolume();
	float MinDeltaV = (float) ((1-EPSREL)*T*0.1); // 90% of nominal pumped volume in T
	activatePump ();
	// Determine pumped volume and compare with target volume
	do{
		Sleep (T); // Waiting for T ms => T*0,1ml nominal
		// Calculate pumped volume since start of measurement
		pumpedVolume = measureWatervolume() - startVolume;
		// Calculate pumped volume sicne last time of measurement
		if (mActualDeltaV < MinDeltaV){
			break; // If pumping result is wrong: cancel process
		}
	} while(pumpedVolume < TargetvolumeInMl);
	deactivatePump ();
	return (pumpedVolume);
}

float Brewingsystem::brewCoffee (float TargetvolumeInMl){
	openWatervalve ();
	activateHeater();  // Fresh water at ambient temperature, turn on heater
	pumpWater (TargetvolumeInMl);
	deactivateHeater(); // Finished: Heater off
	closeWatervalve();
	return (TargetvolumeInMl*(1-(float)0.13*(float) rand()/RAND_MAX));
}

int Brewingsystem::measureWatertemperature (){
	mWatertemperature ++;  // Emulate heating
	return (mWatertemperature);
}

float Brewingsystem::measureWatervolume (){
	float lastVolume;
	// Save last value
	lastVolume = mWatervolume;
	// Measure
	mWatervolume ++;  // Emulate volume flow rate
	// Calculate ActualDeltaV
	mActualDeltaV = mWatervolume - lastVolume;
	return (mWatervolume);
}

int Brewingsystem::heatupWatertank (int TargettemperatureInCelsiusDegrees){
	if (measureWatertemperature() < TargettemperatureInCelsiusDegrees){
		activateHeater ();
		// Measure temperature and compare to target temperature
		do{
			measureWatertemperature();
		} while(mWatertemperature < TargettemperatureInCelsiusDegrees);
		deactivateHeater ();
	}
	return (mWatertemperature);
}
