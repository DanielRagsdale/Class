#ifndef __TREENODE_H__
#define __TREENODE_H__ 

class TreeNode
{
	public:
		int value;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

#endif
