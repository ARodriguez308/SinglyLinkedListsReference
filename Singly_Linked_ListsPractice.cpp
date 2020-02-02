// Singly_Linked_ListsPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Alita Rodriguez
//CST-201 Algorithms and Data Structures

#include <iostream>
using namespace std;
#include "IntSLLNode.h"

int main()
{
	/*
	//create a three-node linked list

	//Use the constructors from the Node class to generate info members of the list
	//generate a node for 10, 8, and 50
	IntSLLNode* p = new IntSLLNode(10); //New object called p, where a node holds the element 10
	
	//The second node is created, and shows why these are considered 'singly linked lists'
	//Now, 8 is assigned to the 'info' member of this node, p and null becomes the next member
	//The arrow notation can also be thought of as p.next (access to the next member of the object p)
	p->next = new IntSLLNode(8);

	//The third node is created
	//the next member of node 8, the second node, is accessed and assigned to be 50
	//The node accesses the third placeholder of the list by accessing the next members of the preceding nodes
	p->next->next = new IntSLLNode(50);

	//Using the Nodes only, output the data stored in each
	cout << "The info stored at the nodes is: " << endl;
	while (p != NULL)
	{
		//show the info stored at each p node
		cout << p->info << " ";
		//The go to the next p node
		p = p->next;
		//Check the condition of the while loop and repeat
	}
	cout << endl;
	cout << endl;
	*/

	//Or: using function members of the List class, add elements to an object
	//first, call an IntSLList object to store the data
	IntSLList List1;

	//Implement the functions of the IntSLList class:
	//Begin with the head, which stores 10
	List1.addToHead(10);
	//add elements afterwards,and since 10 is the only element, its added onto the end
	List1.addToTail(8);
	//Add 50 at the end
	List1.addToTail(50);
	//show the list to the user
	cout << "The info stored by the List1 object is: " << endl;
	List1.displayList();
	cout << endl;

	cout << "Testing copy constructor. . ." << endl;
	IntSLList copylist(List1);

	copylist.displayList();

	cout << "Removing the first element of the list using the copy: " << endl;
	copylist.deleteFromHead();

	copylist.displayList();

	cout << endl << endl;
	cout << "testing sorting. . . " << endl;

	IntSLList List3;

	List3.addToHead(24);
	List3.addToHead(10);
	List3.addToHead(5);
	List3.addToHead(1);
	List3.addToHead(4);

	List3.insertionSort(); //Function to sort an already existing list

	List3.displayList();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
