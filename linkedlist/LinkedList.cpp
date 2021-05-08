#pragma once

#include"LinkedList.h"

//createNode
node* createNode(int _data)
{
	node* NODE = new node;

	if (NODE == NULL)
		return NULL;

	NODE->data = _data;
	NODE->next = NULL;

	return NODE;
}

//createList 
void createList(linkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

// check list 0 size
bool isEmpty(linkedList list)
{
	if (list.head == NULL)
	{
		return true;
	}
	return false;
}

//add head
void addHead(node* Node, linkedList& list)
{
	if (isEmpty(list))
	{
		list.head = Node;
		list.tail = Node;
	}

	else
	{
		Node->next = list.head;
		list.head = Node;
	}
}


//add tail
void addTail(node* Node, linkedList& list)
{
	if (list.head == NULL)
	{
		list.head = Node;
		list.tail = Node;
		return;
	}
	
	list.tail->next = Node;
	list.tail = Node;
	
}

//add behind q
void addBehind(node* Node, linkedList& list, int q)
{
	int temp = getSize(list);
	if (q == 0)
		addHead(Node, list);
	else if (q == temp)
		addTail(Node, list);
	else if (q > temp)
		return;
	else
	{
		node* temp = list.head;
		int i = 0;
		while (i < q-1)
		{
			temp = temp->next;
			i++;
		}
		Node->next = temp->next;
		temp->next = Node;
	}
}

// add at q 
void addAt(node* Node, linkedList& list, int q)
{
	int temp = getSize(list);
	if (q == 1)
		addHead(Node, list);
	else if (q == temp + 1)
		addTail(Node, list);
	else if (q > temp + 1||q<1)
		return;
	else
		addBehind(Node, list, q - 1);
}

//delete at q
void deleteAt(linkedList& list, int q)
{
	int tempInt = getSize(list);
	if (list.head == NULL||q<1||q>tempInt)
		return;
	else if (q == 1)
	{
		node* temp = list.head;
		list.head = list.head->next;
		delete temp;
	}
	else if (q == tempInt)
	{
		node* temp = list.head;
		while (temp->next->next!=NULL)
			temp = temp->next;
		
		list.tail = temp;
		delete temp->next;
		list.tail->next = NULL;
	}

	else
	{
		node* tempNode = list.head;
		int i = 0;
		while (i < q-2)
		{
			tempNode = tempNode->next;
			i++;
		}
		node* temp = tempNode->next;
		tempNode->next = tempNode->next->next;
		delete temp;
	}
}

vector<int>searchNode(linkedList list, int value)
{
	vector<int>Return;
	node* temp = list.head;
	if (temp == NULL)
		return Return;

	int i = 1;
	while (temp!=NULL)
	{
		if (temp->data == value)
			Return.push_back(i);
		i++;
		temp = temp->next;
	}
	
	return Return;
}

//print list
void printList(linkedList list)
{
	node* Node = list.head;

	while (Node!=NULL)
	{
		cout << Node->data << endl;
		Node = Node->next;
	}
}

//get size list
int getSize(linkedList list)
{
	int Count = 0;
	node* Node = list.head;

	while (Node!=NULL)
	{
		Count++;
		Node = Node->next;
	}
	
	return Count;
}