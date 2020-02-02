//Alita Rodriguez
//single-linked list class to store integers

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
/*
//class for integer singly linked list nodes
class IntSLLNode
{
public:

	//Constructor: Initializes the 'next' pointer to null and leaves 'info' unspecified
	IntSLLNode()
	{
		next = 0;
	}

	//Parameterized Constructor: Initializes info member and next member
	IntSLLNode(int el, IntSLLNode* ptr = 0) 
	//can also function when only one numerical argument is supplied
	{ //In the case only one argument is passed, info is the argument, 
		//and next becomes null
		info = el; next = ptr;
	}
	int info;
	IntSLLNode* next;

};*/

//Class for integer singly linked list, allows access to the list with nested Node class
class IntSLList
{
protected:
	//Nested class is protected within the list class
	class IntSLLNode
	{
	public:

		//Constructor: Initializes the 'next' pointer to null and leaves 'info' unspecified
		IntSLLNode()
		{
			next = 0;
		}

		//Parameterized Constructor: Initializes info member and next member
		IntSLLNode(int el, IntSLLNode* ptr = 0)
			//can also function when only one numerical argument is supplied
		{ //In the case only one argument is passed, info is the argument, 
			//and next becomes null
			info = el; next = ptr;
		}
		int info;
		IntSLLNode* next;





	}; //end of IntSLLNode class

public:
	IntSLList();

	//IntSLList(const IntSLList& myList); //copy constructor

	//function defaulting an empty list to 0
	int isEmpty()
	{
		return head == 0;
	}

	//functions used to access the elements of the list
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); //delete the head and return its info
	int deleteFromTail(); //delete the tail and return its info;
	void deleteNode(int);
	bool isInList(int) const;
	void displayList();
	
	//Function to insert a given node in a sorted linked list
	void sortedInsert(struct IntSLLNode** head, struct IntSLLNode* new_node)
	{
		struct IntSLLNode* current;
		//Special case for the head end
		if (*head == NULL || (*head)->info >= new_node->info)
		{
			new_node->next = *head;
			*head = new_node;
		}
		else
		{
			current = *head;
			while (current->next != NULL && current->next->info < new_node->info)
			{
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}//End of sorted insert

	//Function to sort a singly linked list using insertion sort
	void insertionSort()
	{
		struct IntSLLNode* sorted = NULL; //Initialise sorted linked list

		struct IntSLLNode* current = head; //Node to be sorted
		while (current != NULL) //traverse the list
		{
			//Store next for the next iteration
			struct IntSLLNode* next = current->next;
			//Insert current in sorted linked list
			sortedInsert(&sorted, current);
			//Update current
			current = next;
		}
		//update head to point to the now sorted linked list
		head = sorted;
	} //end of insertionSort

private:
	IntSLLNode* head, * tail;
};

#endif //INT_LINKED_LIST

