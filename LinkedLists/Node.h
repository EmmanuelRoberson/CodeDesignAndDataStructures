#pragma once
#include <iostream>

template <typename Type>
struct nodeType
{
	Type info;
	nodeType<Type> * nextLink;
};