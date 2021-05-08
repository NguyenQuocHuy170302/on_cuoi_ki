#include<iostream>
#include<vector>
using namespace std;

class node
{
public:

	int data;
	node* next;	


};

class linkedList
{
public:

	linkedList()
	{
		head = NULL;
		tail = NULL;
	}

	node* head;
	node* tail;

};

//createNode
node* createNode(int _data);

//createList
void createList(linkedList& l);

// check list 0 size
bool isEmpty(linkedList list);

//add head 
void addHead(node* Node, linkedList& list);

//add tail
void addTail(node* Node, linkedList& list);

//add behind q
void addBehind(node* Node, linkedList& list, int q);

// add at q 
void addAt(node* Node, linkedList& list, int q);

//delete at q
void deleteAt(linkedList& list, int q);

//search data
vector<int>searchNode(linkedList list, int value);

//print list
void printList(linkedList list);

//get size list
int getSize(linkedList list);


