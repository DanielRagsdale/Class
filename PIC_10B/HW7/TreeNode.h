#ifndef __TREENODE_H__
#define __TREENODE_H__ 

/**
 * A class containing all of the information needed for a node of
 * a BinarySearchTree
 **/
class TreeNode
{
	public:
		/**
		 * The value of this node
		 **/
		int value;

		/**
		 * The location of the TreeNode down and left of this one
		 **/
		TreeNode* left;

		/**
		 * The location of the TreeNode down and right of this one
		 **/
		TreeNode* right;
		
		/**
		 * Create a TreeNode with a value of val and null left and right ptrs
		 *
		 * @param val the value to be set for this TreeNode
		 **/
		TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

#endif
