#pragma once
#include "Node.h"

template <typename Type>
class listIterator
{
public:
	listIterator();
	listIterator(nodeType<Type>);
	Type operator * ();
	listIterator<Type> operator ++ ();
	bool operator == (const listIterator<Type>&) const;
	bool operator != (const listIterator<Type>&) const;
private:
	nodeType<Type> * current;
};

template<typename Type>
inline listIterator<Type>::listIterator()
{
	current = nullptr;
}

template<typename Type>
inline listIterator<Type>::listIterator(nodeType<Type>)
{
	current = &nodeType<Type>;
}

template<typename Type>
Type listIterator<Type>::operator*()
{
	return current->info;
}

template<typename Type>
listIterator<Type> listIterator<Type>::operator++()
{
	current = current->nextLink;
}

template<typename Type>
bool listIterator<Type>::operator==(const listIterator<Type>&) const
{
	return (current == listIterator<Type>->current);
}

template<typename Type>
inline bool listIterator<Type>::operator!=(const listIterator<Type>&) const
{
	return false;
}
