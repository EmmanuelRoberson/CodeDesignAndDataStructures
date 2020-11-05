#pragma once

template <class T>
class Queue
{
public:

	//constructor
	Queue();

	//returns length of queue
	int Length();

	//tells whether the object is in the queue
	bool Contains(T);

	//copies the contents of the queue to an array, starting at the specified index
	void CopyTo(T[], int);

	//removes and returns the object at the beginning of the queue
	T Dequeue();

	//adds the object to the end of the queue
	void Enqueue(T);

	//tells whether the object is equal to the current queue
	bool Equals(Queue<T>);

	//returns the object at the beginning of the queue without removing it
	T Peek();
private:

	int length;




protected:

};

template<class T>
inline int Queue<T>::Length()
{
	return length;
}
