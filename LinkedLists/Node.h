#pragma once
#include <iostream>

//nodeType is a container for a singular information entry
template <typename Type>
struct nodeType
{
	// A Type that contains actual stored information entry
	Type info;

	//Pointer that contains a reference to the next nodeType in a suquence
	nodeType<Type> * nextLink;
};