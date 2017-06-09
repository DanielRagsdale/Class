#include<iostream>

#include"BinarySearchTree.h"
#include"TreeNode.h"
#include"TreeIterator.h"

/*
*
* Homework # 7
*
* Author: Daniel Ragsdale
*
* Email: danielr@ucla.edu
*
* Course: PIC 10B Lecture 1 Spring 2017
*
* Collaborators:
*
*
*
* Honesty Pledge:
*
* I, Daniel Ragsdale, pledge that this is my independent work and abide by the guidelines of honesty
*
* outlined in the syllabus.
*
*
*
* User inputs:
*
* None
*
* Output:
*
* Your tree consists of : 2,3,5,11,13,
* Tree now consists of  : 2,3,5,13,
* Checking initial value: 2
*
* List of known bugs:
*
* None
*
**/

/**
 * The default main file included with the project assignment.
 **/
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
	
	std::cout << "Your tree consists of : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	bst.erase(6);
	bst.erase(11);
	std::cout << "Tree now consists of  : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	TreeIterator start = bst.begin();
	TreeIterator stop = bst.end();
	std::cout << "Checking initial value: ";
	
	if (start != stop) std::cout << *start++ << std::endl;
}
