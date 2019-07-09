#include <string>

#ifndef SLIST_H
#define SLIST_H

typedef char List_Type;
//declaration for a node in the list
class LIST_NODE
{
public:
	List_Type data; //data element
	LIST_NODE *next; //pointer element
};

//declaration of a list class
class LINKED_LIST_CLASS
{
public:
	LINKED_LIST_CLASS();//default constructor
	~LINKED_LIST_CLASS();
	void Print(); //accessor
	bool Is_Empty() { return front == 0; }; //accessor
	void Insert_FRONT(const List_Type &);
	void Insert_BACK(const List_Type &);
	void Create_List(const string &, LIST_NODE *&, LIST_NODE *&);
	LIST_NODE * Search(const List_Type &);
	void Remove(const List_Type &);
	
private:

	LIST_NODE *front, *back;

};

#endif

