
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Coffeemaker.cpp
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"

#include "stdafx.h"
#include "brewingsystem.h"
#include "grinder.h"
#include "coffeemaker.h"

const Consumptionrate Coffeemaker::mConsumptionrate[3][3]
= { //small, regular , large
	{{50,5},{120,10},{175,15}}, // delicate
	{{50,7},{120,14},{175,21}}, // medium
	{{50,9},{120,18},{175,27}}  // strong
};

const char Coffeemaker::sstext[4][17]={"READY         ", "PRODUCE COFFEE", "DESCALE       ", "ERROR         "};

//Constructor und Destructor
Coffeemaker::Coffeemaker(void){
	mGrinderHandle = new Grinder;
	mBrewingsystemHandle = new Brewingsystem;
	mStatus = sReady;
	GOTOXY(10, 4); printf("%s", sstext[sReady]);
	mStorageHandle = new storageSystem;
}

Coffeemaker::~Coffeemaker(void){
}

bool Coffeemaker::brewCup (sStrength aType, sCupsize bType){
	float ActualVolume;
	int ActualCoffeegrounds;
	int ActualTemperature;
	bool goodQuality = true;

	if (mStatus != sReady){
		return (false); // Brewing coffee only possibe at sReady.
	}

	// Change of state after sBrewing
	mStatus = sBrewing;
	GOTOXY(10, 4); printf("%s", sstext[sBrewing]);

	Consumptionrate Options = mConsumptionrate [(int)aType][(int)bType];
	GOTOXY(10, 5); printf("Vol %dml, Strength %dg                                               ", Options.mlWater, Options.gCoffeegrounds);

	// Grind coffee beans according to selected cup size and coffee strength
	ActualCoffeegrounds = mGrinderHandle->grindCoffeebeans(Options.gCoffeegrounds);
	Sleep(1000);
	if (abs(ActualCoffeegrounds-Options.gCoffeegrounds)>(EPSREL * Options.gCoffeegrounds)){
		goodQuality = false;
	}

	// Pour in coffee grounds
	mGrinderHandle->fillBrewingfilter();
	Sleep(1000);

	// Boil up water
	ActualTemperature = mBrewingsystemHandle->getMHeaterHandle()->heatupWatertank(SETTEMPERATURE);
	if (abs(ActualTemperature-SETTEMPERATURE)>(EPSREL * SETTEMPERATURE)){
		goodQuality = false;
	}

	// Produce coffee
	ActualVolume = mBrewingsystemHandle->brewCoffee((float)Options.mlWater);
	if (fabs(ActualVolume-(float)Options.mlWater)>(EPSREL * (float) Options.mlWater)){
		goodQuality = false;
	}

	// Discard coffee grounds
	mGrinderHandle->emptyBrewingfilter();
	if (goodQuality==true){
		GOTOXY(10, 5); printf("Your Coffee is ready! Remove cup.                                   ");
	}
	else{
		PreparationError();
	}

	return (goodQuality);
}

void Coffeemaker::removeCup (){
	if (mStatus == sBrewing){
		//Preheat water tank to Tanktemperature
		mBrewingsystemHandle->getMHeaterHandle()->heatupWatertank(TANKTEMPERATURE);

		// Change of state after sReady
		mStatus = sReady;
		GOTOXY(10, 4); printf("%s", sstext[sReady]);
		GOTOXY(10, 5); printf(DEFAULTMESSAGE);
	}
}

void Coffeemaker::Ready (){
	if ((mStatus == sDescaling)|| (mStatus == sError)){
		// Change of state after sReady
		mStatus = sReady;
		GOTOXY(10, 4); printf("%s", sstext[sReady]);
		GOTOXY(10, 5); printf(DEFAULTMESSAGE);
	}
}

void Coffeemaker::CleaningError (){
	if (mStatus == sDescaling){
		// Change of state after sError
		mStatus = sError;
		GOTOXY(10, 4); printf("%s", sstext[sError]);
		GOTOXY(10, 5); printf("Error during cleaning! Please contact service team.                   ");
	}
}

void Coffeemaker::PreparationError (){
	if (mStatus == sBrewing){
		// Change of state after sError
		mStatus = sError;
		GOTOXY(10, 4); printf("%s", sstext[sError]);
		GOTOXY(10, 5); printf("Error during preparation! Please contact service team.                ");
	}
}


bool Coffeemaker::descale (){
	bool ok = false;
	if (mStatus != sReady){
		return (ok); // Descaling only possible at sReady.
	}

	// Change of state after sDescaling
	mStatus = sDescaling;
	GOTOXY(10, 4); printf("%s", sstext[sDescaling]);
	GOTOXY(10, 5); printf("please wait until coffeemachine has finished descaling.                ");

	// Descaling in process
	Sleep(5000);
	ok = true;

	if (ok==true){
		GOTOXY(10, 5); printf("Descaling finished.                                                 ");
		mStatus = sReady;
		GOTOXY(10, 4); printf("%s", sstext[sReady]);
		GOTOXY(10, 5); printf(DEFAULTMESSAGE);
	}
	else{
		CleaningError();
	}

	return (ok);
}

void Coffeemaker::Screen(void) {
	std::string Slot1Name = mStorageHandle->displaySlot(0),
				Slot2Name = mStorageHandle->displaySlot(1);

	system("cls");
	GOTOXY(1, 1); printf("Coffeemachine - (c) AU-Lab");
	GOTOXY(1, 2); printf("-----------------------------------------------------------------------------");
	GOTOXY(1, 4); printf("Status : Ready                                                               ");
	GOTOXY(1, 5); printf("Note   : Please select                                                       ");
	GOTOXY(1, 6); printf("Setting: Cup Size: REGULAR,  Strength: MEDIUM, Coffeetype: %s                ", Slot1Name.c_str());
	//X                   0123456789          0123456789          0123456789
	//X                             0123456789          0123456789
	GOTOXY(1, 7); printf("-----------------------------------------------------------------------------");
	GOTOXY(1, 10); printf("Cup Size     : small     (s), regular (r), large  (l)                       ");
	GOTOXY(1, 11); printf("Strength     : delicate  (d), medium  (m), strong (g)                       ");
	GOTOXY(1, 12); printf("Coffeetype   : %-10s(1), %-8s(2),									", Slot1Name.c_str(), Slot2Name.c_str());
	GOTOXY(1, 13); printf("Produce coffee           (p)");
	GOTOXY(1, 14); printf("Cup removed              (c)");
	GOTOXY(1, 15); printf("Descale                  (a)");
	GOTOXY(1, 16); printf("Exit programm            (x)\n");
}

void Coffeemaker::run (){
	bool drinkable;
	char theCommand =' ';
	sCupsize vc = regularCup;
	sStrength vs = sMedium;
	char vctext[][8]={"SMALL  ",   "REGULAR", "LARGE  "};
	char vstext[][9]={"DELICATE", "MEDIUM  ",  "STRONG  "};
	

	Screen();
	
	do{
		if (_kbhit()){
			theCommand = _getch();
			switch (theCommand){
				case 's': {
					vc = smallCup;
					GOTOXY(20, 6); printf("%s", vctext[smallCup]);
					break;
				}
				case 'r': {
					vc = regularCup;
					GOTOXY(20, 6); printf("%s", vctext[regularCup]);
					break;
				}
				case 'l': {
					vc = largeCup;
					GOTOXY(20, 6); printf("%s", vctext[largeCup]);
					break;
				}
				case 'd': {
					vs = sDelicate;
					GOTOXY(40, 6); printf("%s", vstext[sDelicate]);
					break;
				}
				case 'm': {
					vs = sMedium;
					GOTOXY(40, 6); printf("%s", vstext[sMedium]);
					break;
				}
				case 'g': {
					vs = sStrong;
					GOTOXY(40, 6); printf("%s", vstext[sStrong]);
					break;
				}
				case '1': {
					std::string tmpStr = mStorageHandle->displaySlot(0);
					GOTOXY(60, 6); printf("%s", tmpStr.c_str());
					break;
				}
				case '2': {
					std::string tmpStr = mStorageHandle->displaySlot(1);
					GOTOXY(60, 6); printf("%s", tmpStr.c_str());
					break;
				}
				case 'p': {
					drinkable = brewCup(vs, vc);
					break;
				}
				case 'c': {
					removeCup();
					break;
				}
				case 'a': {
					descale();
					break;
				}
				case 'y': {
					Ready();
					break;
				}
			}
		}

		
		} while(theCommand != 'x');
}
