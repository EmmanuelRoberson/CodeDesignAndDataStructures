#include "queue.h"
#include <iostream>

int main()
{
	//TEST CASES FOR QUEUE<T>

	std::cout << " -- TEST CASES FOR QUEUE -- " << std::endl;

	//instantiate queue class
	Queue<int> numberQueue(1);

	//print the length to the console
	std::cout << "Queue length :: " + numberQueue.Length() << std::endl;


	return 0;
}