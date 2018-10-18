#include "LinkedListExtended.h"

int main()
{
	nodeType<int>* node1 = new nodeType<int>;
	nodeType<int>* node2 = new nodeType<int>;
	nodeType<int>* node3 = new nodeType<int>;
	nodeType<int>* node4 = new nodeType<int>;
	node1->info = 5;
	node2->info = 33;
	node3->info = 47;
	node4->info = 49;
	
	linkedListExtended<int>* testList = new linkedListExtended<int>();
	testList->insertFirst(node1->info); //inserting first and last works
	testList->insertFirst(node2->info);
	testList->insertLast(node3->info);
	testList->insertLast(node4->info);
	testList->print(); //expected: 33 5 47 49 :: test: 33 5 47 49

	testList->begin(); //expected: current points to same as first :: test: current point to same as first
	testList->end(); //expected: current points to same as last:: test: current point to same as last

	//testList->destroyList(); //destroyList works
	//testList->print();//expected: EMPTY LIST :: test:

	//deleting first/middle/last :: works
	//check to see if i can delete more than one thing :: works
	//testList->deleteNode(node4->info);
	//testList->print();//49 will be missing
	//testList->deleteNode(node2->info);
	//testList->print();//33 will be missing
	//testList->deleteNode(node1->info);
	//testList->print();//5 will be missing
	//testList->deleteNode(node3->info);
	//testList->print();//47 will be missing

	//testList->isEmptyList(); //expected: false :: test : false
	//testList->search(5); //expected: true :: test:
	//testList->length(); //expected: 4 :: test : 4
	//testList->front(); //expected: 33 :: test: 33
	//testList->back(); //expected: 49:: test: 49

	linkedListExtended<int>* testList2(testList); // works
}