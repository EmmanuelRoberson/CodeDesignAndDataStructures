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
	testList->isEmptyList(); //expected: false :: test : false
	testList->search(5); //expected: true :: test: true
	testList->deleteNode(node4->info); //deleting works
}