#ifndef STORAGESYSTEM_H
#define STORAGESYSTEM_H

#include "stdafx.h"
#include "StorageVessel.h"

class StorageVessel;

class storageSystem {

private:
	StorageVessel* Slots[2];

public:
	storageSystem();

	~storageSystem();

	void VesselMaintainance();

	std::string displaySlot();
};

#endif
