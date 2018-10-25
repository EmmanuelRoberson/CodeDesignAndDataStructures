#pragma once
#include "LinkedListBase.h"

template <class T>
class linkedListExtended : public linkedListBase<T>
{
public:
	bool search(const T&) const override;//
	void insertFirst(const T&) override;//
	void insertLast(const T&) override;//
	void deleteNode(const T&) override;//
};

template<class T>
bool linkedListExtended<T>::search(const T& t) const
{
	nodeType<T>* type = new nodeType<T>{ t };
	for (int i = 0; i < this->count; i++)
	{
		if (type->info == t)
			return true;
	}
	return false;
}

template <class T>
void linkedListExtended<T>::deleteNode(const T& t)
{
	if (this->isEmptyList() == false)
	{
		nodeType<T>* deleter = this->first, *trail = this->first;
		if (t == this->first->info)
		{
			this->first = this->first->nextLink;
			delete deleter;
			this->count--;
		}
		else if (t == this->last->info)
		{
			for (int i = 0; i < this->count - 2; i++)
				deleter = deleter->nextLink;
			this->last = deleter;
			deleter = deleter->nextLink;
			delete deleter;
			this->count--;
		}
		else
		{
			deleter = deleter->nextLink;
			while (deleter->info != t)
			{
				deleter = deleter->nextLink;
				trail = trail->nextLink;
			}
			trail->nextLink = deleter->nextLink;
			delete deleter;
			this->count--;
		}
	}
}

template<class T>
void linkedListExtended<T>::insertFirst(const T& t)
{
	if (this->count == 2)
	{
		this->first->nextLink = this->last;
	}
	nodeType<T>* node = new nodeType<T>;
	node->info = t;
	this->count++;

	if (this->first == nullptr)
	{
		this->first = node;
		if (this->last == nullptr)
		{
			this->last = node;
		}
	}
	else
	{
		node->nextLink = this->first;
		this->first = node;
	}
}

template <class T>
void linkedListExtended<T>::insertLast(const T& t)
{
	if (this->count == 2)
	{
		this->first->nextLink = this->last;
	}
	nodeType<T>* node = new nodeType<T>{ t };
	this->count++;

	if (this->last == nullptr)
	{
		this->last = node;
		if (this->first == nullptr)
		{
			this->first = node;
		}
	}
	else
	{
		this->last->nextLink = node;
		this->last = node;
	}
	this->last->nextLink = nullptr;
}