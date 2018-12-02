#include <iostream>

//bubble sort from least to greatest
template <class Type>
void BubbleSort(Type arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				Type temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int testArray[10] = { 4, 52, 3, 5, 6, 63, 62, 19, 23, 55 };

	BubbleSort<int>(testArray, 10);

}
