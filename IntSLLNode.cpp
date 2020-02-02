#include <iostream>
#include "IntSLLNode.h"
using namespace std;

//Default Constructor
IntSLList::IntSLList()
{
	for (IntSLLNode* p; !isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

//Insert value at the front
void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}

//Insert value at the end
void IntSLList::addToTail(int el)
{
	if (tail != 0) //if list is not empty;
	{
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el); //Otherwise the head and tail are the same thing
}

//Remove value at front
int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode* tmp = head;
	if (head == tail) //if only one node in the list;
	{
		head = tail = 0;
	}
	else head = head->next;
	delete tmp;
	return el;
}

//Remove value from the tail
int IntSLList::deleteFromTail()
{
	int el = tail->info;
	if (head == tail) //if only one node in the list;
	{
		delete head;
		head = tail = 0;
	}
	else //If there is not one node in the list, then there must be more than one
	{
		IntSLLNode* tmp; //find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp; //the predecessor of tail becomes tail;
		tail->next = 0;
	}
	return el;
}

void IntSLList::deleteNode(int el)
{
	if (head != 0) //if not empty list;
	{
		if (head == tail && el == head->info) // if only one node in the list;
		{
			delete head;
			head = tail = 0;
		}
		else if (el == head->info) //if more than one node in the list
		{
			IntSLLNode* tmp = head;
			head = head->next;
			delete tmp; //an old head is deleted;
		}
		else //if more than one node in the list
		{
			IntSLLNode* pred, * tmp;
			for (pred = head, tmp = head->next; //and a nonhead node
				tmp != 0 && !(tmp->info == el); //is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != 0)
			{
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const
{
	//temporary node created to check
	IntSLLNode* tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

void IntSLList::displayList()
{
	IntSLLNode* ptr;
	ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
	cout << endl;
}