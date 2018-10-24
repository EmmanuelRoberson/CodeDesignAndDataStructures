#include "HashFunction.h"

unsigned int HashFunction::badHash(const char * data, unsigned int length)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < length; ++i)
		hash += data[i];
	return hash;
}

unsigned int HashFunction::erHash(std::string string)
{
	char* ptr = &string[0];
	unsigned int hash = int(string[0]);
	for (unsigned int i = 0; i < strlen(ptr); ++i)
		hash += int(string[i]);
	return hash << hash;
}