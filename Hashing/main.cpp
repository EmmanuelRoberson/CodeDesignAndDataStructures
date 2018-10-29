#pragma once
#include "HashContainer.h"

int main()
{
	HashContainer<std::string> ages;
	ages.add("Emmanuel", "ER");
	ages.add("Robert", "RR");
	std::string myName = ages["ER"];
}