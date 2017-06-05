#ifndef __INTLIST_H__
#define __INTLIST_H__

#include"Node.h"

class IntList
{
public:	
	Node* first;

	IntList(Node node);
	IntList(int val);
	IntList();

	void reverse();
	void push_front(int val);
	void sort();
	void merge(IntList& o);
};
#endif
