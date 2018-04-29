
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Brewingssystem.h
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"


//..begin "Ifdef"
#ifndef _Brewingsystem_H_
#define _Brewingsystem_H_
//..end "Ifdef"


//..begin "pragma"
#pragma once
//..end "pragma"

#include "globaldefines.h"
#include "stdafx.h"

class Brewingsystem
{	
	
	//..begin "UserDefined"
	// put some additional code here
	//..end "UserDefined"
	
	private:
//		enum ssBrewingystem{ bsReady, bsHeatup, bsPump, bsError };
		/**
		possible status: ready, heatup, pump, error
		*/
//		ssBrewingsystem mStatus;
	
	public:
		Brewingsystem (void );
		~Brewingsystem (void );
		bool activateHeater ();
		bool deactivateHeater ();
		bool activatePump ();
		bool deactivatePump ();
		bool openWatervalve ();
		bool closeWatervalve ();
		float pumpWater (float TargetvolumeInMl);
		float brewCoffee (float TargetvolumeInMl);
		int measureWatertemperature (); 	/**	Value in �C	*/
		float measureWatervolume ();

	int heatupWatertank(int TargettemperatureInDegreesCelsius);		/**	Value in �C	*/
	
	private:
		float mWatervolume;	/**	latest count of the water meter, value in ml */
		float mActualDeltaV;		/**	watervolume as difference between the two latest times of measurement, value in ml	*/
		int mWatertemperature;	/**	Thermometer, value in �C	*/
};



//..begin "Endif"
#endif
