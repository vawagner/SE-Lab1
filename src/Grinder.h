#ifndef GRINDER_H
#define GRINDER_H

class Grinder {

private:
	/**
	 * typedef enum ssGrinder {gReady, gGrinding, gFilling, gEmptying, gError};
	 * ssGrinder gStatus;
	 */
	eGrindingdegree mGrindingdegree;

public:
	Grinder(void unnamed_1);

	~Grinder(void unnamed_1);

	int grindCoffeebeans(int Targetamount);

	bool fillBrewingfilter();

	bool emptyBrewingfilter();
};

#endif
