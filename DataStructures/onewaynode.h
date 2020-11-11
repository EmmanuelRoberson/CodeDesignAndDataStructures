#pragma once
#include "node.h"

template <class T>
struct OneWayNode : Node<T>
{
public:
	Node<T>* nextNode;
};