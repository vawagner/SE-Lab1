
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

class Heater;
class Pump;

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
		float brewCoffee (float TargetvolumeInMl);
		Heater* getMHeaterHandle();
		Pump* getMPumpHandle();
	
	private:
		Heater * mHeaterHandle;
		Pump * mPumpHandle;
};



//..begin "Endif"
#endif
