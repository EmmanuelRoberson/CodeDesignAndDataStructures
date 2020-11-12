#include "queue.h"
#include <iostream>

int main()
{
	//TEST CASES FOR QUEUE<T>

	std::cout << " -- TEST CASES FOR QUEUE -- " << std::endl;

	//instantiate queue class
	Queue<int> numberQueue(1);

	//length() test
	printf("Expected results :: 1");
	std::cout << "Queue length :: " + numberQueue.Length() << std::endl;

	//contains() tests
	printf("Expected results:: True");
	std::cout << numberQueue.Contains(1) << std::endl;
	printf("Expected results:: False");
	std::cout << numberQueue.Contains(1) << std::endl;

	//copyto() tests
	int numArray[5];
	numberQueue.CopyTo(numArray, 5, 0);

	int numArrayTwo[1];
	numberQueue.CopyTo(numArrayTwo, 1, 9);

	int numArrayThree[1];
	numberQueue.CopyTo(numArray, 3, 0);

	int numArrayFour[3];
	//numberQueue.CopyTo(numArray, 0)



	return 0;
}