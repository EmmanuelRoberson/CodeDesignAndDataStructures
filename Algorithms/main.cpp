#include "LinkListWithInsertAtNode.h"

template <class T>
nodeType<T> LowestHealth(linkedListExtended<T>* list)
{
	listIterator<T> temp = list->begin();
	nodeType<T> lowest = { *temp };
	for (int i = 0; i < list->length(); i++)
	{
		if (*temp < lowest.info)
			lowest.info = *temp;
		++temp;
	}
	return lowest;
}

template <class T>
nodeType<T> BubbleSort(linkedListWithInsertNode<T> * list)
{
	//keeps track of the lowest values
	listIterator<T> temp1 = list->begin(), temp2 = list->begin();

	for (int i = 0; i < list->length(); i++)
	{
		for (int j = i; j <= list->length(); j++)
		{
			if (*temp2 < *temp1)
			{
				//moves value
				T tempVar = *temp2;
				list->deleteNode(*temp2);
				list->insertBefore(*temp1, tempVar);
				//resets the loop, and moves iterators to the beginning
				temp1 = list->begin();
				for (int k = 0; k < i; i++)
					++temp1;
				j = i;
				continue;
			}
			++temp2;
		}
		++temp1;
	}
	nodeType<T> node = { list->front() };
	return node;
}

int main()
{
	//returning lowest health using lists (not bubble sort)
		nodeType<int>* player1 = new nodeType<int>{ 10 };
		nodeType<int>* player2 = new nodeType<int>{ 20 };
		nodeType<int>* player3 = new nodeType<int>{ 30 };
		nodeType<int>* player4 = new nodeType<int>{ 40 };
		nodeType<int>* player5 = new nodeType<int>{ 50 };

		linkedListWithInsertNode<int>* players = new linkedListWithInsertNode<int>();
		players->insertFirst(player3->info);
		players->insertFirst(player5->info);
		players->insertFirst(player2->info);
		players->insertFirst(player4->info);
		players->insertLast(player1->info);

		//LowestHealth(players);

		BubbleSort<int>(players);
}
