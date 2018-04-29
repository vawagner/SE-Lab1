
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Coffeemaker.h
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"


//..begin "Ifdef"
#ifndef _Coffeemaker_H_
#define _Coffeemaker_H_
//..end "Ifdef"


//..begin "pragma"
#pragma once
//..end "pragma"

#include "globaldefines.h"

typedef struct {
	int mlWater;
	int gCoffeegrounds;
} Consumptionrate;
typedef enum sStrength {sDelicate=0, sMedium, sStrong};
typedef enum sCupsize{smallCup=0, regularCup, largeCup};

class Grinder;
class Brewingsystem;

class Coffeemaker
{	
	public:
		void Screen ();
		void run ();
		bool brewCup (sStrength aType, sCupsize bType);
		bool descale ();
		void removeCup ();
		void Ready ();
		void CleaningError ();
		void PreparationError ();
		Coffeemaker(void);
		~Coffeemaker(void);
	
	private:
		typedef enum ssSystem {sReady=0, sBrewing, sDescaling, sError};
		static const char sstext[4][17];
		ssSystem mStatus;
		Grinder * mGrinderHandle;
		Brewingsystem * mBrewingsystemHandle;
		/**
		Setting water and coffee grounds amount according to selected cup size and coffee strength
		Lines: Strength (delictae, medium, strong)
		Columns: Cup size (small, regular, large)
		*/
		static const Consumptionrate mConsumptionrate [ 3 ] [ 3 ];
	storageSystem* mStorageHandle;  // Class variable
	
};


//..begin "Endif"
#endif
