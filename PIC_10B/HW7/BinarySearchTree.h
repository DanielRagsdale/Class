#ifndef __BINARYSEARCHTREE_H_
#define __BINARYSEARCHTREE_H_

#include<iterator>

#include"TreeNode.h"
#include"TreeIterator.h"

/**
 * Class providing the interface to a binary search tree.
 */
class BinarySearchTree
{
	public:
		/**
		 * Pointer to the location of the root node
		 */
		TreeNode* root;
		
		/**
		 * Create a BinarySearchTree with the root pointer set to nullptr
		 **/	
		BinarySearchTree() : root(nullptr) {}

		/**
		 * Create a BinarySearchtree with the root pointer set to r
		 *
		 * @param r the location of the root node
		 **/
		BinarySearchTree(TreeNode* r) : root(r) {}
		
		/**
		 * Add the provided value to this BinarySearchTree
		 * Does nothing if the value is already present
		 *
		 * @param val the value to be added
		 **/
		void insert(int val);

		/**
		 * Remove the provided value from this BinarySearchTree
		 * Does nothing if the value does not exist
		 *
		 * @param val the value to be removed
		 **/
		void erase(int val);

		/**
		 * Provides a pointer to the pointer in the tree that points to the node of val
		 * Returns nullptr if val is not in the tree
		 *
		 * @param val the value of the node to be found
		 *
		 * @return double pointer to the location of the val node
		 **/
		TreeNode** find(int val);
		
		/**
		 * Create a TreeIterator at the smallest node of this tree
		 *
		 * @return a TreeIterator initialized to the smallest node
		 **/
		TreeIterator begin();

		/**
		 * Create a TreeIterator at the largest node of this tree
		 *
		 * @return a TreeIterator intialized to the largest node
		 **/
		TreeIterator end();
};

#endif








