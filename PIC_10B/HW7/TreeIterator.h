#ifndef __TREEITERATOR_H__
#define __TREEITERATOR_H__

#include<iterator>
#include<vector>

#include"TreeNode.h"

/**
 * Object that can be used to iterate through a BinarySearchTree or subtree
 **/
class TreeIterator 
{
	private:
		TreeNode* root;

	public:
		/**
		 * The path this iterator took to arrive at the current node
		 */
		std::vector<TreeNode*> path;

		/**
		 * Create a tree iterator with r as its root node
		 * Initializes this iterator to point to the smallest element of the tree
		 *
		 * @param r a pointer to the root node of this subtree
		 **/
		TreeIterator(TreeNode* r);
		
		/**
		 * Move the iterator to the largest element of the tree
		 **/	
		void back();
		
		/**
		 * Return the value of the TreeNode currently pointed at by this TreeIterator
		 *
		 * @return the value of the current TreeNode
		 **/
		int& operator*();

		/**
		 * Move this iterator to the next largest value
		 *
		 * @return this TreeIterator after it has been incremented
		 **/
		TreeIterator& operator++();
		TreeIterator operator++(int dummy);

		/**
		 * Move this iterator to the next smallest value
		 *
		 * @return this TreeIterator after it has been decremented
		 */
		TreeIterator& operator--();
		TreeIterator operator--(int dummy);
};

/**
 * Check if lhs and rhs point to the same value
 * If lhs and rhs are members of the same tree, this checks if lhs and rhs point to the same node
 *
 * @param lhs the first TreeIterator to be compared
 * @param rhs the second TreeIterator to be compared
 *
 * @return true if lhs and rhs point to the same value
 */
bool operator==(TreeIterator lhs, TreeIterator rhs);

/**
 * Check if lhs and rhs point to different values
 * If lhs and rhs are members of the same tree, this checks if lhs and rhs point to different nodes
 *
 * @param lhs the first TreeIterator to be compared
 * @param rhs the second TreeIterator to be compared
 *
 * @return true if lhs and rhs point to different values
 */
bool operator!=(TreeIterator lhs, TreeIterator rhs);

#endif






