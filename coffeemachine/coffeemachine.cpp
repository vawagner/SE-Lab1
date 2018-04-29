//Coffeemachine.cpp : Defines point of access to the console application.
//

#include "src/stdafx.h"

// global variables
COORD xyPos;
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

int _tmain(int argc, _TCHAR* argv[]){
	
	Coffeemaker* theCoffeemaker;

	theCoffeemaker = new Coffeemaker;
	theCoffeemaker->run();
	
	return 0;
}

