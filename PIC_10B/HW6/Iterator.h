#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include"IntList.h"
#include"Node.h"

class Iterator
{
private:
	Node** activeNode;
public:
	Iterator(IntList& list) : activeNode(&(list.first)) {}
	Iterator(Node* n) : activeNode(&n) {}
	Iterator(Node** n) : activeNode(n) {}

	void insert(int val);
	void erase();
	bool has_next();
	Node*& get_node();
	
	int operator*();
	bool operator==(const Iterator& o);
	bool operator!=(const Iterator& o);
	
	Iterator& operator++();
	Iterator& operator++(int dummy);
};
	
Iterator& operator+=(Iterator& o, int val);
#endif
