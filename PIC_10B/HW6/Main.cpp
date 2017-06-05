#include<iostream>

#include"IntList.h"
#include"Iterator.h"
#include"Node.h"

void printList(IntList& l);

int main()
{
	std::cout << "Please input a set of nonnegative numbers for a list." << std::endl;
	std::cout << "(Enter -1 when you are finished):" << std::endl;	

	IntList l;
	Iterator it0(l);

	while(true)
	{
		int input;	
		std::cin >> input;	

		if(input == -1)
		{
			break;
		}

		it0.insert(input);
		++it0;
	}

	std::cout << "Your list is:" << std::endl;
	
	printList(l);

	std::cout << std::endl;

	while(true)
	{
		int index;
		std::cout << "Select and index for insertion (enter -1 when finished): ";
		std::cin >> index;
		if(index == -1)
		{
			break;

		}
		int val;
		std::cout << "Select a value for insertion: ";
		std::cin >> val;
	
		Iterator it2(l);
		for(int i = 0; i < index; i++)
		{
			++it2;
		}	
		it2.insert(val);
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "The augmented list is: " << std::endl;
	printList(l);
	std::cout << std::endl;

	std::cout << "When we sort the previous list we obtain: " << std::endl;
	l.sort();
	printList(l);

	std::cout << "And this sorted list in reverse order is: " << std::endl;
	l.reverse();
	printList(l);


	IntList m(11);
	m.push_front(7);
	m.push_front(5);
	m.push_front(3);
	m.push_front(2);

	std::cout << "If we merge this list with the list (2,3,5,7,11) we obtain: " << std::endl;
	l.merge(m);
	printList(l);
}

void printList(IntList& l)
{
	Iterator it1(l);
	std::cout << "(";
	while(it1.has_next())
	{
		std::cout << *it1 << ",";
		++it1;
	}
	std::cout << "\b)" << std::endl;
}







