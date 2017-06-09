#ifndef __TREEITERATOR_H__
#define __TREEITERATOR_H__

#include<iterator>
#include<vector>

#include"TreeNode.h"

class TreeIterator 
{
	private:
		TreeNode* root;
		std::vector<TreeNode*> path;

	public:
		TreeIterator(TreeNode* r);

		void back();

		int& operator*();
		TreeIterator& operator++();
		TreeIterator operator++(int dummy);
		TreeIterator& operator--();
		TreeIterator operator--(int dummy);
};

bool operator==(TreeIterator lhs, TreeIterator rhs);
bool operator!=(TreeIterator lhs, TreeIterator rhs);

#endif
