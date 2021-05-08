#include"LinkedList.h"
#include<ctime>

int main()
{

	linkedList list;
	createList(list);
	
	srand(time(NULL));
	for (size_t i = 0; i <100; i++)
	{
		node* NODE = createNode(i);
		addTail(NODE, list);
	}
	node* temp = createNode(2);
	//addAt(temp, list,10);
	//deleteAt(list, 5);
	//printList(list);
	//addTail(temp, list);
	//cout << getSize(list);
	vector<int>pos= searchNode(list, 99);
	cout << pos[0];
	return 0;
}