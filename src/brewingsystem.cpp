
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Brewingsystem.cpp
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"


#include "stdafx.h"
#include "brewingsystem.h"

Brewingsystem::Brewingsystem (void ){
	mPumpHandle = new Pump;
	mHeaterHandle = new Heater;
}

Brewingsystem::~Brewingsystem (void ){

}



float Brewingsystem::brewCoffee (float TargetvolumeInMl){
	mPumpHandle->openWatervalve ();
	mHeaterHandle->activateHeater();  // Fresh water at ambient temperature, turn on heater
	mPumpHandle->pumpWater (TargetvolumeInMl);
	mHeaterHandle->deactivateHeater(); // Finished: Heater off
	mPumpHandle->closeWatervalve();
	return (TargetvolumeInMl*(1-(float)0.13*(float) rand()/RAND_MAX));
}

Heater * Brewingsystem::getMHeaterHandle()
{
	return mHeaterHandle;
}

Pump * Brewingsystem::getMPumpHandle()
{
	return mPumpHandle;
}





