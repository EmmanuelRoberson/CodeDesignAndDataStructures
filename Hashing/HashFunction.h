#pragma once
#include <cmath>
#include <iostream>

namespace HashFunction
{
	//implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);

	//ADD FUNCTIONS HERE
	unsigned int erHash(std::string);
}
