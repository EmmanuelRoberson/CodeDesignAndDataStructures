#pragma once
#include "node.h"

template <class T>
struct OneWayNode : Node<T>
{
	Node<T>* nextNode;
};