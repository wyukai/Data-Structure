#ifndef NODETREE_H
#define NODETREE_H

//树结点
//要素：索引  数据  左孩子指针 右孩子指针 父结点指针


class NodeTree
{
public:
	NodeTree();
	NodeTree *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	int index;
	int data;
	NodeTree *pLChild;
	NodeTree *pRChild;
	NodeTree *pParent;

private:

};

#endif // !NODETREE_H
