#ifndef __BINARYSEARCHTREE_H_
#define __BINARYSEARCHTREE_H_

#include<iterator>

#include"TreeNode.h"
#include"TreeIterator.h"

class BinarySearchTree
{
	public:
		TreeNode* root;
		
		BinarySearchTree() : root(nullptr) {}
		BinarySearchTree(TreeNode* r) : root(r) {}

		void insert(int val);
		void erase(int val);
		TreeNode** find(int val);

		TreeIterator begin();
		TreeIterator end();
};

#endif


