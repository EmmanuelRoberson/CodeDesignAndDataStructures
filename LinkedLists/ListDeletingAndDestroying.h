#pragma once
#include "ListInsertingAndSearching.h"

template <class T>
class listDeleteDestroy : listInsertSearch<T>
{
	void destroyList() override;
	void deleteNode(const T&) override;
};

template <class T>
void listDeleteDestroy<T>::destroyList()
{

}

template <class T>
void listDeleteDestroy<T>::deleteNode(const T& t)
{

}