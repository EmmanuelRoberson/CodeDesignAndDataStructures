#pragma once
#include "LinkedListIterator.h"

template <typename Type>
class linkedListBase
{
public:
	const linkedListBase<Type>& operator = (const linkedListBase<Type>&);
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
	linkedListBase(const linkedListBase<Type>&);
	~linkedListBase();
protected:
	int count;
	nodeType<Type>* first;
	nodeType<Type>* last;
private:
	void copyList(const linkedListBase<Type>&);
};

template<typename Type>
const linkedListBase<Type>& linkedListBase<Type>::operator=(const linkedListBase<Type>& other)
{
	copyList(other);
	return *this;
}

template<typename Type>
void linkedListBase<Type>::initializeList()
{
	first = nullptr, last = nullptr, count = 0;	
}

template<typename Type>
bool linkedListBase<Type>::isEmptyList() const
{
	return (count == 0);
}

template<typename Type>
void linkedListBase<Type>::print() const
{
	//if list is empty
	if (isEmptyList() == true)
	{
		std::cout << "EMPTY LIST" << std::endl;
		return;
	}

	nodeType<Type>* iter = first;
	for (int i = 0; i < count; i++)
	{
		std::cout << iter->info << " ";
		iter = iter->nextLink;
	}
	std::cout << std::endl;
}

template<typename Type>
int linkedListBase<Type>::length() const
{
	return count;
}

template<typename Type>
void linkedListBase<Type>::destroyList()
{
	if (isEmptyList() == false)
	{
		//dont use count in condition, because deleteNode() affects count
		for (int i = 0, j = count; i < j; i++)
			deleteNode(first->info);
	}
	initializeList();
}

template<typename Type>
Type linkedListBase<Type>::front() const
{
	//returns info of node that first is pointing to
	return first->info;
}

template<typename Type>
Type linkedListBase<Type>::back() const
{
	//returns info of node that last is pointing to
	return last->info;
}

template<typename Type>
listIterator<Type> linkedListBase<Type>::begin()
{
	listIterator<Type> iter(first);
	return iter;
}

template<typename Type>
listIterator<Type> linkedListBase<Type>::end()
{
	listIterator<Type> iter(last);
	return iter;
}

template<typename Type>
linkedListBase<Type>::linkedListBase()
{
	initializeList();
}

template<typename Type>
linkedListBase<Type>::linkedListBase(const linkedListBase<Type>& other)
{
	initializeList();
	copyList(other);
}

template<typename Type>
linkedListBase<Type>::~linkedListBase()
{
	initializeList();
}

template<typename Type>
void linkedListBase<Type>::copyList(const linkedListBase<Type>& other)
{
	destroyList();
	listIterator<Type> temp = begin();
	for(int i = 0; i < count; i++)
	{
		//i used insert last so the order of the nodes would be the same
		insertLast(*temp);
		temp++;
	}
}
