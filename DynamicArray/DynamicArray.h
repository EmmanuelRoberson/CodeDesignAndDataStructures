#include <iostream>

template <class Type>
class DynamicArray
{
public:
	
	DynamicArray();

	void InsertLast(Type&);

	void Delete(Type&);

	Type GetData(int);

private:

	Type* data;

	int filled_indexes;

	int total_length;
};

template<class Type>
DynamicArray<Type>::DynamicArray()
{
	filled_indexes = 0;
	total_length = 2;
	data = new Type[total_length];
}

template<class Type>
void DynamicArray<Type>::InsertLast(Type & new_data)
{
	if (filled_indexes == total_length)
	{
		total_length *= 2;
		Type* temp = new Type[total_length * 2];
		int tempLength = 0;
		while (tempLength < total_length)
		{
			temp[tempLength] = data[tempLength];
			tempLength++;
		}

		delete data;
		data = temp;

		data[filled_indexes++] = new_data;
	}
	else
	{
		data[filled_indexes++] = new_data;
	}
}

template<class Type>
void DynamicArray<Type>::Delete(Type & deleted_data)
{
	Type* temp = new Type[total_length];
	int tempCurr = 0;

	for (int i = 0; i < filled_indexes; i++)
	{
		if (data[i] != deleted_data)
		{
			temp[tempCurr++] = data[i];
		}
	}
	filled_indexes--;
	delete data;
	data = temp;
}

template<class Type>
 Type DynamicArray<Type>::GetData(int index)
{
	 return data[index];
}
