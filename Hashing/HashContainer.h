#pragma once
#include "HashFunction.h"
#include <string>
using namespace HashFunction;

template <class T>
class HashContainer
{
private:
	T* collection = new T[100];
	unsigned int containerSize;
	unsigned int* hashTable = new int[100];
	int length;
public:
	HashContainer<T>();
	void add(T, std::string);
};


template<class T>
HashContainer<T>::HashContainer()
{
	length = 0;
	containerSize = 100;
}

template<class T>
void HashContainer<T>::add(T data, std::string string)
{
	unsigned int key = HashFunction::erHash(string);
	hashTable[key % 100] = key;
	collection[key % 100] = data;
}

//overloaded subscript operator goes here
