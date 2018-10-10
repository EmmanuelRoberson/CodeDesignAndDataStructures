#pragma once
#include <iostream>

template <typename Type>
struct nodeType
{
	Type info;
	nodeType * nextLink;
};