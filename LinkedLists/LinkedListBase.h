#pragma once
#include "LinkedListIterator.h"

template <typename Type>
class linkedListBase
{
public:
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;
	virtual bool search(const Type&) const = 0;
	virtual void insertFirst(const Type&) = 0;
	virtual void insertLast(const Type&) = 0;
	virtual void deleteNode(const Type&) = 0;
	listIterator<Type> begin();
	listIterator<Type> end();
	linkedListBase();
	linkedListBase(const listIterator<Type>&);
	~linkedListBase();
protected:
	int count;
	nodeType<Type>* first;
	nodeType<Type>* last;
private:
};

template<typename Type>
void linkedListBase<Type>::initializeList()
{
	first = nullptr, last = nullptr, count = 0;	
}

template<typename Type>
bool linkedListBase<Type>::isEmptyList() const
{
	return false;
}

template<typename Type>
void linkedListBase<Type>::print() const
{
}

template<typename Type>
int linkedListBase<Type>::length() const
{
	return 0;
}

template<typename Type>
void linkedListBase<Type>::destroyList()
{
}

template<typename Type>
Type linkedListBase<Type>::front() const
{
	return Type();
}

template<typename Type>
Type linkedListBase<Type>::back() const
{
	return Type();
}

template<typename Type>
listIterator<Type> linkedListBase<Type>::begin()
{
	return listIterator<Type>();
}

template<typename Type>
listIterator<Type> linkedListBase<Type>::end()
{
	return listIterator<Type>();
}

template<typename Type>
linkedListBase<Type>::linkedListBase()
{
	initializeList();
}

template<typename Type>
linkedListBase<Type>::linkedListBase(const listIterator<Type>&)
{
}

template<typename Type>
linkedListBase<Type>::~linkedListBase()
{
}
