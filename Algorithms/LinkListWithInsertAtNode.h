#pragma once
#include "LinkedListExtended.h"

template <class T>
class linkedListWithInsertNode : public linkedListExtended<T>
{
public:
	void InsertBefore(const T&, const T&);
};

template<class T>
 void linkedListWithInsertNode<T>::InsertBefore(const T & existingNode, const T & insertedNode)
{
	 nodeType<T>* iter1 = this->first, *trail = this->first;
	 iter = iter->nextLink;
	 while (iter->info != existingNode)
	 {
		 iter = iter->nextLink;
		 trail = trail->nextLink;
	 }
	 nodeType<T>* temp = new nodeType<T>{ insertedNode };
	 trail->nextLink = temp;
	 temp->nextLink = iter;
}
