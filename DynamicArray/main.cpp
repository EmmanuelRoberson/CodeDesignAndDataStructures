#include "DynamicArray.h"

int main()
{
	DynamicArray<int>* test = new DynamicArray<int>();

	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	test->InsertLast(nums[0]);
	test->InsertLast(nums[1]);
	//expected
	//total will be 4, filled indexes will be 3
	test->InsertLast(nums[2]);
	//result
	//total be 4, filled indexes be 3
	test->InsertLast(nums[3]);

	//expected
	//total will be 8, filled indexes will be 5
	test->InsertLast(nums[4]);
	//result
	//total be 8, filled indexes be 5

	//expected
	//total will be 8, filled indexes will be 4
	test->Delete(nums[0]);
	//result
	//total be 8, indexes be 4

	int temp = test->GetData(2);
}