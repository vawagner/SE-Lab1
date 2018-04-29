#include "storageSystem.h"
#include "stdafx.h"

storageSystem::storageSystem() {
	// TODO - implement storageSystem::storageSystem
	Slots[0] = new StorageVessel("ARABICA");
	Slots[1] = new StorageVessel("ROBUSTA");
}

storageSystem::~storageSystem() {
	delete(Slots[0]);
	delete(Slots[1]);
}

std::string storageSystem::displaySlot(int num) {
	return Slots[num]->getCoffeetype();
}
