#include"IntList.h"
#include"Iterator.h"

#include<iostream>

IntList::IntList(Node node) : first(&node) {}

IntList::IntList(int val)
{
	Node* n = new Node(0, val);
	first = n;
}

IntList::IntList() : first(0) {}

void IntList::reverse()
{
	IntList l;
	Iterator iter(*this);
	
	while(iter.has_next())
	{	
		l.push_front(*iter);	
		++iter;
	}

	first = l.first;
}


void IntList::push_front(int val)
{
	Node* n = new Node(first, val);
	first = n;
}

void printList(Node** l, int len)
{
	Iterator it1(l);
	std::cout << "(";
	for(int i = 0; i < len; i++)
	{
		std::cout << *it1 << ",";
		++it1;
	}
	std::cout << "\b)" << std::endl;
}

/**
  * Sort the list in place.
  **/
void IntList::sort()
{
	int len = 0;
	Iterator it(*this);
	while(it.has_next())
	{
		++len;
		++it;
	}
	
	for(int i = 0; i < len; i++)
	{
		Node** workingVal = &first;
			
		for(int j = 0; j < len - i - 1; j++)
		{
			if((**workingVal).payload > (**workingVal).next->payload)
			{
				Node* a = *workingVal;
				Node* b = (**workingVal).next;
				Node* c = (**workingVal).next->next;
				


				(**workingVal).next->next = a;	
				(**workingVal).next = c;
				*workingVal = b;
			}
			
			workingVal = &((**workingVal).next);
		}
	}
}

void IntList::merge(IntList& o)
{
	Iterator it0(*this);
	Iterator it1(o);

	while(it1.has_next())
	{
		if(it0.has_next())
		{
			++it0;
		}
		it0.insert(*it1);
		++it0;
		++it1;
	}
}
