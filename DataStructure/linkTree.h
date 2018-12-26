#ifndef LINKTREE_H
#define LINKTREE_H
#include "nodeTree.h"
class LinkTree
{
public:
	LinkTree();
	~LinkTree();
	NodeTree *SearchNode(int nodeIndex); //ËÑË÷Ê÷½áµã
	bool AddNode(int nodeIndex,int direction,NodeTree *pNode);
	bool DeleteNode(int nodeIndex, NodeTree *pNode);
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
private:
	NodeTree *m_pRoot;
};




#endif // !LINKTREE_H

