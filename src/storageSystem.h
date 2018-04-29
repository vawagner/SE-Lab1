#ifndef STORAGESYSTEM_H
#define STORAGESYSTEM_H

class storageSystem {

private:
	StorageVessel* Slots[2];

public:
	storageSystem();

	~storageSystem();

	void VesselMaintainance();

	string displaySlot();
};

#endif
