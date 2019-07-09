#include <iostream>
#include <string>

#include "slist.h"

using namespace std;

int main()
{
	LINKED_LIST_CLASS L;
  //TESTING INSERT_FRONT A NODE INTO THE FRONT OF A LIST
	L.Insert_FRONT('h');
	L.Insert_FRONT('e');
	L.Insert_FRONT('l');
	L.Insert_FRONT('l');
	L.Insert_FRONT('o');
	L.Print();

	L.Remove('o');
	L.Print();

	L.Remove('h');
	L.Print();

	L.Remove('l');
	L.Print();

	//TESTING INSERT_BACK
	LINKED_LIST_CLASS K;
	K.Insert_BACK('h');
	K.Insert_BACK('e');
	K.Insert_BACK('l');
	K.Insert_BACK('l');
	K.Insert_BACK('o');
	K.Print();

	//TESTING Create_List 
	LINKED_LIST_CLASS M;
	string s = "xyz123abc";
	LIST_NODE *first = 0 , *last = 0;
	M.Create_List(s, first, last);
	M.Print();
	return 0;
}
