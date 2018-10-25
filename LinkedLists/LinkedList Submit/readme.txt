	Here are my Linked List functions and member variables, and what they are suppossed to accomplish:
	
	first				 :: pointer to the first node in the list		
	last				 :: pointer to the last node in the list
	count				 :: keeps track of the number of nodes in the list
	
	initializeList() 	 :: sets first and last to null, and initializes count to 0;
	isEmptyList() 		 :: returns a bool based on if the list contains at least one node
	print() 			 :: prints the values in each node from first to last to the console
	length()			 :: returns the amount of nodes in the list
	destroyList()		 :: deletes each node in the list
	front()				 :: returns the value in the first node of the list
	back()				 :: returns the value in the last node of the list
	search(Type&)		 :: returns a bool based on if the list contains a node with the value of the argument
	insertFirst(Type&)	 :: inserts a new node, that contains the value of the argument,before the first node
	insertLast(Type&)	 :: inserts a new node, that contains the value of the argument,after the last node
	deleteNode(Type&)	 :: deletes the node containing the value of the argument
	begin()				 :: returns a listIterator whose current is pointing to the first node of the list
	end()				 :: returns a listIterator whose current is pointing to the last node of the list
	linkedListBase()	 :: constructor that calls initializeList()
	linkedListBase(linkedListBase&) :: constructor that calls initializeList(), then sets calls copyList(linkedListBase&)
	copyList(linkedListBase&)		:: calls destroyList(), then inserts copies of every node from the argument list
	
	Here is how I attempted to complete each function:
	
	initializeList()	 :: I set first and last to nullptr, then count to 0
	isEmptyList()		 :: I returned the condition (count == 0)
	print()				 :: If the list is empty, I printed "EMPTY LIST" to the console and returned.
							If the list isnt empty, I used a nodeType pointer to iterate through each node, from first to last,
							and printed the the each node's info to the console;
	length()			 :: I returned count
	destroyList()		 :: If the list isnt empty, I 
//LINK LIST BASE FUNCTIONS

	linkedListExtended<int>* testList = new linkedListExtended<int>();

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