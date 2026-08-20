#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> list;
	list.AddToHead(30);
	list.AddToHead(20);
	list.Insert(10);
	
	list.Insert(60);
	list.Insert(50);
	list.Insert(40);

	list.Print();
}