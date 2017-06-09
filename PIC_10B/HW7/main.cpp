#include<iostream>

#include"BinarySearchTree.h"
#include"TreeNode.h"
#include"TreeIterator.h"

int main()
{
	BinarySearchTree bst;
	
	bst.insert(3);
   	bst.insert(2);
   	bst.insert(11);
   	bst.insert(13);
   	bst.insert(5);
   	bst.insert(17);
   	bst.insert(17);

   	bst.insert(-10);
   	bst.insert(1);
   	bst.insert(0);
   	bst.insert(7);
   	bst.insert(8);

	std::cout << "Your tree consists of : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	bst.erase(6);
	bst.erase(7);
	bst.erase(11);
	std::cout << "Tree now consists of  : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	TreeIterator start = bst.begin();
	TreeIterator stop = bst.end();
	std::cout << "Checking initial value: ";
	
	if (start != stop) std::cout << *start++ << std::endl;
}
