#pragma once
#include "Node.h"

template <typename Type>
class listIterator
{
public:
	listIterator();
	listIterator(nodeType<Type>*);
	Type operator * ();
	listIterator<Type> operator ++ ();
	bool operator == (const listIterator<Type>&) const;
	bool operator != (const listIterator<Type>&) const;
private:
	nodeType<Type>* current;
};

template<typename Type>
inline listIterator<Type>::listIterator()
{
	current = nullptr;
}

template<typename Type>
listIterator<Type>::listIterator(nodeType<Type>* ex)
{
	current = ex;
}

template<typename Type>
Type listIterator<Type>::operator*()
{
	return this->current->info;
}

template<typename Type>
listIterator<Type> listIterator<Type>::operator++()
{
	//pre-increment
	this->current = this->current->nextLink;
	return *this;
}

template<typename Type>
bool listIterator<Type>::operator==(const listIterator<Type>& it) const
{
	return (this->current->info == *it);
}

template<typename Type>
bool listIterator<Type>::operator!=(const listIterator<Type>& it) const
{
	return (current != it.current);
}
