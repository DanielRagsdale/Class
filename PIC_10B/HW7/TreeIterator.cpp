#include"TreeIterator.h"
#include"BinarySearchTree.h"

TreeIterator::TreeIterator(TreeNode* r) : root(r), path() 
{
	path.push_back(root);
	
	while(path.back()->left != nullptr)
	{
		path.push_back(path.back()->left);
	}
}

void TreeIterator::back()
{
	path.clear();
	path.push_back(root);

	while(path.back()->right != nullptr)
	{
		path.push_back(path.back()->right);
	}
}


int& TreeIterator::operator*()
{
	return path.back()->value;
}

TreeIterator& TreeIterator::operator++()
{
	if(path.back()->right != nullptr)
	{
		path.push_back(path.back()->right);

		while(path.back()->left != nullptr)
		{
			path.push_back(path.back()->left);
		}

		return *this;
	}

	if(path.size() > 1 && path.back() == path[path.size() - 2]->left)
	{
		path.pop_back();
		return *this;
	}

	while(path.size() > 1 && path.back() == path[path.size() - 2]->right)
	{
		path.pop_back();		
	}
	path.pop_back();		
	return *this;
}

TreeIterator TreeIterator::operator++(int dummy)
{
	TreeIterator temp = *this;
	this->operator++();
	return temp;
}

TreeIterator& TreeIterator::operator--()
{
	if(path.back()->left != nullptr)
	{
		path.push_back(path.back()->left);

		while(path.back()->right != nullptr)
		{
			path.push_back(path.back()->right);
		}

		return *this;
	}

	if(path.size() > 1 && path.back() == path[path.size() - 2]->right)
	{
		path.pop_back();
		return *this;
	}

	while(path.size() > 1 && path.back() == path[path.size() - 2]->left)
	{
		path.pop_back();		
	}
	path.pop_back();		
	return *this;
}

TreeIterator TreeIterator::operator--(int dummy)
{
	TreeIterator temp = *this;
	this->operator--();
	return temp;
}

bool operator==(TreeIterator lhs, TreeIterator rhs)
{
	return *lhs == *rhs;
}

bool operator!=(TreeIterator lhs, TreeIterator rhs)
{
	return *lhs != *rhs;
}





