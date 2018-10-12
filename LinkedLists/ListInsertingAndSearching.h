#pragma once
#include "LinkedListBase.h"

template <class T>
class listInsertSearch : linkedListBase<T>
{
	bool search(const T&) const override;
	void insertFirst(const T&) override;
	void insertLast(const T&) override;
};

template<class T>
bool listInsertSearch<T>::search(const T& t) const
{
	listIterator<T>* frst = new listIterator<T>(*first);
	listIterator<T>* lst = new listIterator<T>(*last);
	while (frst != lst)
	{
		if (*frst == t)
		{
			delete last;
			return true;
		}
		frst++;
	}
	return false;
}

template<class T>
void listInsertSearch<T>::insertFirst(const T& t)
{
	nodeType<T>* node = new nodeType<T>;
	node->info = t;

	node->nextLink = first;
	first = *node;
}

template <class T>
void listInsertSearch<T>::insertLast(const T& t)
{
	nodeType<T>* node = new nodeType<T>;
	node->info = t;

	last->nextLink = *node;
}