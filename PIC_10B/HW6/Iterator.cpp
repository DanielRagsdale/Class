#include"Iterator.h"
#include"IntList.h"	
#include"Node.h"

void Iterator::insert(int val)
{
	*activeNode = new Node(*activeNode, val);
}

void Iterator::erase()
{
	Node* temp = (*activeNode)->next;
	delete activeNode;
	*activeNode = temp;
}

bool Iterator::has_next()
{
	return *activeNode != 0;
}
	
Node*& Iterator::get_node()
{
	return *activeNode;
}

int Iterator::operator*()
{
	return (**activeNode).payload;
}

bool Iterator::operator==(const Iterator& o)
{
	return *activeNode == *o.activeNode;
}

bool Iterator::operator!=(const Iterator& o)
{
	return *activeNode != *o.activeNode;
}

Iterator& operator+=(Iterator& o, int val)
{
	for(int i = 0; i < val; i++)
	{
		++o;
	}	
	return o;
}

Iterator& Iterator::operator++()
{
	activeNode = &((*activeNode)->next);
	return *this;
}

Iterator& Iterator::operator++(int dummy)
{
	activeNode = &((*activeNode)->next);
	return *this;
}


