#include "LinkedListExtended.h"

int main()
{
	nodeType<int>* node1 = new nodeType<int>{ 5 };
	nodeType<int>* node2 = new nodeType<int>{ 10 };
	nodeType<int>* node3 = new nodeType<int>{ 15 };
	nodeType<int>* node4 = new nodeType<int>{ 20 };

	//LINK LIST BASE FUNCTIONS

	linkedListExtended<int>* testList = new linkedListExtended<int>();
	linkedListExtended<int> begin;

	//expected:: true is returned
	testList->isEmptyList();
	//test:: true is returned

	//expected:: '5 10 15 20' is printed to the console
	testList->insertLast(node1->info);
	testList->insertLast(node2->info);
	testList->insertLast(node3->info);
	testList->insertLast(node4->info);
	testList->print();
	//expected:: '5 10 15 20' is printed to the console

	//expected:: 4 is returned
	testList->length();
	//test:: 4 is returned

	//expected:: count is 0, first is NULL, last is NULL
	testList->destroyList();
	//expected:: count is 0, first is NULL, last is NULL

	//expected:: 5 is returned
	testList->insertLast(node1->info);
	testList->insertLast(node2->info);
	testList->insertLast(node3->info);
	testList->insertLast(node4->info);
	testList->front();
	//test:: 5 is returned

	//expected:: 20 is returned
	testList->back();
	//test:: 20 is returned

	//extected:: iterator whose current is pointing to the same thing as first
	testList->begin();
	//test:: iterator whose current is pointing to the same thing as first

	//expected:: iterator whose current is pointing to the same thing as last
	testList->end();
	//test:: rator whose current is pointing to the same thing as last

	//expected:: a new list containing copies of nodes, of the list in the argument, is created
	linkedListExtended<int>* testList2(testList);
	//test:: testList2's first and last's address is the same as testList's
	//cannot create copies, beacause arguments take in the reference to the info passed in

	//LINK LIST EXTENDED FUNCTIONS

	//expected:: true is returned
	testList->search(node1->info);
	//test:: true is returned

	//expected:: testList's first->info is 100, count is 5
	testList->insertFirst(100);
	//test:: testList's first->info is 100, count is 5

	//expected:: testList's last->info is 200, count is 6
	testList->insertLast(200);
	//test::  testList's last->info is 200, count is 6

	//expected:: testList's last->info is 20, count is 5
	testList->deleteNode(200);
	//test:: testList's last->info is 20, count is 5

	//LIST ITERATOR FUNCTIONS

	//expected:: current is pointing to the same thing as first
	listIterator<int> iter(testList->begin());
	//test::   current is pointing to the same thing as first

	//expected:: 100 is returned
	*iter;
	//test:: 100 is returned

	//expected:: current->info is 5
	++iter;
	//test:: current->info is 5

	//done
}