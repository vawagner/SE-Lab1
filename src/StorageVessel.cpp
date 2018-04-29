#include "StorageVessel.h"
#include "stdafx.h"

StorageVessel::StorageVessel() {
	this->Coffeetype = "";
}

StorageVessel::StorageVessel(string type) {
	this->Coffeetype = type;
}

StorageVessel::~StorageVessel() {

}

std::string StorageVessel::getCoffeetype() {
	return Coffeetype;
}


