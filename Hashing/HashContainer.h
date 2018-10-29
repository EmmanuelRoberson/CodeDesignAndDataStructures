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
	unsigned int* hashTable = new unsigned int[100];
	int length;

public:
	T& operator[] (const std::string);
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
T& HashContainer<T>::operator[](const std::string keyword)
{
	unsigned int index = HashFunction::erHash(keyword) % 100;
	return collection[index];
}

template<class T>
//data is data to be inserted, string is the keyword
void HashContainer<T>::add(T data, std::string keyword)
{
	unsigned int key = HashFunction::erHash(keyword);
	hashTable[key % 100] = key;
	collection[key % 100] = data;
}