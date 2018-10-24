#pragma once
#include "LinkedListExtended.h"

template <class T>
class linkedListWithInsertNode : public linkedListExtended<T>
{
public:
	void insertBefore(const T&, const T&);
};

template<class T>
 void linkedListWithInsertNode<T>::insertBefore(const T & existingNode, const T & insertedNode)
{
	 nodeType<T>* iter = this->first, *trail = this->first;

	 if (iter->info == existingNode)
	 {
		 nodeType<T>* temp = new nodeType<T>{ insertedNode };
		 temp->nextLink = this->first;
		 this->first = temp;
	 }
	 else
	 {
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
	 this->count++;
}
