#pragma once
#include "onewaynode.h"

template <class T>
class Queue
{
public:

	//constructor
	Queue(T);

	//destructor
	~Queue();

	//returns length of queue
	int Length();

	//tells whether the object is in the queue
	bool Contains(T);

	//copies the each data entry in the queue to an array starting from the specified index of the queue
	void CopyTo(T[], int, int);

	//removes and returns the object at the beginning of the queue
	T Dequeue();

	//adds the object to the end of the queue
	void Enqueue(T);

	//tells whether the object is equal to the current queue
	bool Equals(Queue<T>);

	//returns the object at the beginning of the queue without removing it
	T Peek();

	//returns the placement in the queue in which the argument is located, returns -1 if the argument was not located
	int GetIndexOf(T aData);

private:

	//length of the queue
	int m_Length;

	//start of the queue
	OneWayNode<T>* m_Start;

	//end of the queue
	OneWayNode<T>* m_End;

protected:

};

template<class T>
inline Queue<T>::Queue(T aData)
{
	m_Start = new OneWayNode<T>();
	m_Start->data = aData;

	m_Length = 1;
}

template<class T>
inline Queue<T>::~Queue()
{
	//point a trailing pointer at the start
	OneWayNode<T>* pTrail = m_Start;

	//as long as the starting node has a next node
	while (m_Start->nextNode != nullptr)
	{
		//move start to its next node
		m_Start = m_Start->nextNode;

		//delete the trailing pointer's data
		delete pTrail;

		//move the trailing pointer to the new starting node
		pTrail = m_Start;
	}

	//delete the very last node in the queue
	delete pTrail;
}

template<class T>
inline int Queue<T>::Length()
{
	return m_Length;
}

template<class T>
inline bool Queue<T>::Contains(T aData)
{
	OneWayNode<T>* pIterator = m_Start;

	//while the iterator is not a null pointer
	while (pIterator != nullptr)
	{
		//if the data in the node equates to the argument
		if (pIterator->data == aData)
			return true;

		//points the pointer to the next node in the queue
		pIterator = pIterator->nextNode;
	}

	//will return false if the data does not equate to the argument
	return false;
}

template<class T>
inline void Queue<T>::CopyTo(T aTargetArray[], int aArraySize, int aQueueIndex)
{
	//returns if the array size is less zero below below
	if (aArraySize <= 0)
		return;

	//returns if the queue is empty, or the queue index argument is greater then the length
	if (Length <= 0 || aQueueIndex >= Length())
	{
		return;
	}

	OneWayNode<T>* pIterator = m_Start;

	//iterates the pointer to the specified index in the queue
	for (int i = 0; i < aQueueIndex; i++)
	{
		pIterator = pIterator->nextNode;
	}

	int arrayIndex = 0;

	//while iterator is not a null pointer
	while (pIterator != nullptr)
	{
		//assign de-referenced data from the queue
		aTargetArray[arrayIndex] = *pIterator->data;

		//point the pointer to the next node in the queue
		pIterator = pIterator->nextNode;

		arrayIndex++;

		//returns so the index doesnt go past the array size
		if (arrayIndex >= arraySize)
			return;
	}
}

template<class T>
inline T Queue<T>::Dequeue()
{
	//store the data at the beginning of the queue in a local variable
	T dataCopy = *m_Start->data;

	//point a placeholder to keep track of the old start
	OneWayNode<T>* pPlaceHolder = m_Start;

	//iterate the start pointer to the next node in the queue
	m_Start = m_Start->nextNode;

	//delete the old start data
	delete pPlaceHolder;

	m_Length--;

	return dataCopy;
}

template<class T>
inline void Queue<T>::Enqueue(T aData)
{
	//instantite the the end node pointer's next node
	m_End->nextNode = new OneWayNode<T>();

	//assign the end node pointer to its next node
	m_End = m_End->nextNode;

	//assing the data at the end to the argument
	m_End->data = aData;

	m_Length++;
}

template<class T>
inline bool Queue<T>::Equals(Queue<T> aOtherQueue)
{
	//returns whether both queue's have the same start, end, and length
	return
		m_Start == aOtherQueue.m_Start &&
		m_End == aOtherQueue.m_End &&
		m_Length == aOtherQueue.m_Length;
}

template<class T>
inline T Queue<T>::Peek()
{
	//stores a copy of the data in the start of the queue
	T copyOfStart = &m_Start->data;
	
	return copyOfStart;
}

template<class T>
inline int Queue<T>::GetIndexOf(T aData)
{
	//point an iterator at the beginning of the queue
	OneWayNode<T>* pIterator = m_Start;

	int index = 0;
	while (pIterator->nextNode != nullptr) 
	{
		//if the iterator contains data that equates to the argument, return the index
		if (*pIterator->data == aData)
			return index;

		//move the iterator to its next node
		pIterator = pIterator->nextNode;
		
		index++;
	}

	return -1;
}


