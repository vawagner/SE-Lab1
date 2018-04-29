#ifndef STORAGEVESSEL_H
#define STORAGEVESSEL_H

#pragma once

#include "stdafx.h"
#include <string>


class StorageVessel {

private:
	std::string Coffeetype;

public:
	StorageVessel();

	~StorageVessel();

	std::string getCoffeetype();
};

#endif
