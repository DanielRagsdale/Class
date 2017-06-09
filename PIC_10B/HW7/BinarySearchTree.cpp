#include<iostream>
#include<iterator>

#include"BinarySearchTree.h"
#include"TreeNode.h"
#include"TreeIterator.h"

void BinarySearchTree::insert(int val)
{
	TreeNode** addLoc = find(val);
		
	*addLoc = new TreeNode(val);
}

void BinarySearchTree::erase(int val)
{
	TreeNode** valLoc = find(val);

	if(*valLoc == nullptr)
	{
		return;
	}

	TreeNode** left = &(**valLoc).left;

	if(*left == nullptr)
	{
		TreeNode* temp = *valLoc;
		*valLoc = (**valLoc).right;
		delete temp;
		return;
	}

	while((**left).left != nullptr)
	{
		left = &(**left).left;	
	}

	TreeNode** right = &(**left).right;
	while(*right != nullptr)
	{
		right = &(**right).right;
	}

	TreeNode* tempL = *left;
   	//*left = (*tempL).right;	//remove min node from bottom of tree

	//(*tempL).left = (**valLoc).left; //point min node to locations of removed node 
	(*tempL).left = nullptr; //Nothing in this subtree is left of the min node

	*right = (**valLoc).right; 

	delete *valLoc; //free memory from the erased node

	*valLoc = tempL; //put the min node in the place of the removed node

}
		
TreeNode** BinarySearchTree::find(int val)
{
	TreeNode** nextLoc = &root;
	
	while(*nextLoc != nullptr)
	{
		if(val < (**nextLoc).value)
		{
			nextLoc = &(**nextLoc).left;
		}
		else if(val > (**nextLoc).value)
		{
			nextLoc = &(**nextLoc).right;
		}
		else
		{
			return nextLoc; 
		}
		
	}

	return nextLoc;
}


TreeIterator BinarySearchTree::begin()
{
	return TreeIterator(root);
}

TreeIterator BinarySearchTree::end()
{
	TreeIterator ti(root);
	ti.back();
	return ti;
}



















