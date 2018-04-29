
//..begin "File Description"
/*--------------------------------------------------------------------------------*
   Filename   : Grinder.h
   Description: 
 *--------------------------------------------------------------------------------*/
//..end "File Description"


//..begin "Ifdef"
#ifndef _Grinder_H_
#define _Grinder_H_
//..end "Ifdef"


//..begin "pragma"
#pragma once
//..end "pragma"

#include "globaldefines.h"
#include "stdafx.h"


typedef enum eGrindingdegree {rough=0, medium, fine} eGrindingdegree;

class Grinder
{	
	public:
		Grinder(void);
		~Grinder(void);
		int grindCoffeebeans (int Targetamount);
		bool fillBrewingfilter ();
		bool emptyBrewingfilter ();
	
	private:
//		typedef enum ssGrinder {gReady, gGrinding, gFilling, gEmptying, gError};
//		ssGrinder gStatus;
		eGrindingdegree mGrindingdegree; /** enumeration: rough, medium, fine */
};

//..begin "Endif"
#endif //_Grinder_H_
//..end "Endif"
