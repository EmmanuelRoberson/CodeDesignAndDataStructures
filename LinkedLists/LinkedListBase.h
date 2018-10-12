#pragma once
#include "LinkedListIterator.h"

template <typename Type>
class linkedListBase
{
public:
	void initializeList();
	virtual bool isEmptyList() const = 0;
	virtual void print() const = 0;
	virtual int length() const = 0;
	virtual void destroyList() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
	virtual bool search(const Type&) const = 0;
	virtual void insertFirst(const Type&) = 0;
	virtual void insertLast(const Type&) = 0;
	virtual void deleteNode(const Type&) = 0;
	virtual listIterator<Type> begin() = 0;
	virtual listIterator<Type> end() = 0;
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

//template<typename Type>
//bool linkedListType<Type>::isEmptyList() const
//{
//	return (count == 0);
//}
//
//template<typename Type>
//Type linkedListType<Type>::front() const
//{
//	return first->info;
//}
//
//template<typename Type>
//inline Type linkedListType<Type>::back() const
//{
//	return last->info;
//}
//
//template<typename Type>
//void linkedListType<Type>::insertFirst(const Type &)
//{
//	nodeType<Type>* temp = new nodeType<Type>;
//
//}

template<typename Type>
linkedListBase<Type>::linkedListBase()
{
	initializeList();
}
