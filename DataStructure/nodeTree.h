#ifndef NODETREE_H
#define NODETREE_H

//�����
//Ҫ�أ�����  ����  ����ָ�� �Һ���ָ�� �����ָ��


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
