#include <iostream>
#include <string>
#include "slist.h"

using namespace std;


//The default constructor is used to initialize the state of class.
//In this case, the state are the pointers, front and back.
LINKED_LIST_CLASS::LINKED_LIST_CLASS()
{
	cout << "Inside the default constructor\n";
	front = back = 0;

}

//The destructor will de-allocate all the memory allocated by the LIST_NODE class.
LINKED_LIST_CLASS::~LINKED_LIST_CLASS()
{
	while (front != 0)
	{
		LIST_NODE *p = front;
		front = front->next;
		delete p;
	}
}

//The following function, Print, prints all the data stored in the
//linked list of the current object. In this case, printing starts at
//the front of the list. 
void LINKED_LIST_CLASS::Print()//accessor
{

	LIST_NODE *p = front;
	cout << endl << endl;
	while (p != 0)
	{
		cout << p->data << endl;
		p = p->next;
	}
	cout << endl << endl;
}

//The function, Insert_FRONT, adds a new List_Type data item to the front
//of the linked list.  If the list is NULL, memory is allocated for a
//new node, and key is stored in the data field, and 0 (NULL) is stored in the next field,
//and front and back are set to point to the node.
//
//If the list is not NULL, memory is allocated for a new node, 
//and key is stored in the data field, and front is stored in the next field,
//and front is set to point to the node.
void LINKED_LIST_CLASS::Insert_FRONT(const List_Type & key)
{

	if (front == 0)
	{
		front = new LIST_NODE;
		front->data = key;
		front->next = 0;
		back = front;
	}
	else
	{
		LIST_NODE *p = new LIST_NODE;

		p->data = key;
		p->next = front;
		front = p;
	}

}

//The function, Insert_BACK, adds a new List_Type data item to the front
//of the linked list.  If the list is NULL, memory is allocated for a
//new node, and key is stored in the data field, and 0 is stored in the next field,
//and front and back are set to point to the node.
//
//If the list is not null, memory is allocated for a new node, 
//and key is stored in the data filed, and front is stored in the next field,
//and front is set to point to the node.
void LINKED_LIST_CLASS::Insert_BACK(const List_Type & key)
{
	if (front == 0)
	{
		front = new LIST_NODE;
		front->data = key;
		front->next = 0;
		back = front;
	}
	else
	{
		LIST_NODE *p = new LIST_NODE;
		p->next = 0;
		p->data = key;
		back->next = p;
		back = p;
	}
}

//The function Create_List creates a linked list from the string s.  A copy of all
//the characters in s, are placed into separate nodes in the linked list.
//The aux_front and aux_back represent pointers to the newly created front
//and back nodes of the linked list.
void LINKED_LIST_CLASS::Create_List(const string & s, LIST_NODE *&aux_front, LIST_NODE *&aux_back)
{
	aux_front = aux_back = 0;

	if (front == 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			Insert_BACK(s[i]);
		}
	}
}

//The function Search, performs a sequential search on the link list.
//If key is found, at pointer to its node is returned, otherwise 0.
LIST_NODE * LINKED_LIST_CLASS::Search(const List_Type & key)
{

   LIST_NODE *p = front;//initialize p to front to help in the 
                        //traversal of the list

	while (p != 0)  //traverse (iterate through list)
	{
		if (p->data == key) //check if key equal to data in current node
		{
			return p;       //key located, return its location in list
		}
		p = p->next; //move to next node in the list
	}
	return p; //return location if found, otherwise 0 (null)

}

//The function, Remove, removes the node containing the key, if it is in the list, 
//from any location (front, back, and between front and back).
void LINKED_LIST_CLASS::Remove(const List_Type & key)
{
	//p=0 if key not in list; otherwise p holds the address of the node key is in.
	LIST_NODE *p = Search(key); //check to see if key in list

	//key was not found
	if (p == 0)  //key was not found in the list
	{
		cout << key << "\n" << " not in list\n";
	}
	else  //this block is executed because key was found in the list
	{
		//Remove the front node; there is only one node in the list
		if (p == front && front == back) 
		{
			delete p;
			front = back = 0;
		}
		//Remove the front node; there are at least 2 nodes in the list
		else if (p == front)
		{
			front = front->next;
			delete p;
		}
		//front does not contain key and there are at least 2 nodes
		else
		{
			LIST_NODE *back_ptr = front;

			//find node before the node that contains key
			while (back_ptr != 0 && back_ptr->next != p)
			{
				back_ptr = back_ptr->next;
			}
			//if key is in the last node, set back to node before last node
			if (p == back) 
			{
				back = back_ptr;
			}
			back_ptr->next = p->next;
			delete p;
		}
	}
}


