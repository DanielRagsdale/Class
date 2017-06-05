#ifndef __NODE_H__
#define __NODE_H__
class Node
{
public:
	Node* next;
	int payload;

	Node(Node* n, int v) : next(n), payload(v) {}
};
#endif
