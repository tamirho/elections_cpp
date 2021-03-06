#pragma once
#include <iostream>
#include "SimpleElections.h"

namespace elections {


class ElectionsLoader
{
	// A class to load and save elections according to the type of the election (deal with polymorphism)

public:
	static Elections* load(std::istream& in);
	static void save(std::ostream& out, Elections* elections);
};

}
