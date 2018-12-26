#include "linkTree.h"
#include <stdlib.h>
#include <iostream>;

LinkTree::LinkTree()
{
	//初始化根节点
	m_pRoot = new NodeTree();
}

LinkTree::~LinkTree()
{
	DeleteNode(0,NULL);//m_pRoot->DeleteNode();
}

NodeTree *LinkTree::SearchNode(int nodeIndex) {
	return m_pRoot->SearchNode(nodeIndex);
}

bool LinkTree::AddNode(int nodeIndex, int direction, NodeTree *pNode) {
	NodeTree *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}
	NodeTree *nodeTree = new NodeTree();
	if (nodeTree==NULL)
	{
		return false;
	}
	nodeTree->index = pNode->index;
	nodeTree->data = pNode->data;
	//指定父结点
	nodeTree->pParent = temp;

	if (direction==0) {
		temp->pLChild = nodeTree;
	}
	if (direction==1)
	{
		temp->pRChild = nodeTree;
	}

	return true;
}
bool LinkTree::DeleteNode(int nodeIndex, NodeTree *pNode) {
	NodeTree *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}

	if (pNode!= NULL) {
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;

}

void LinkTree::PreorderTraversal() {
	m_pRoot->PreorderTraversal();
}
void LinkTree::InorderTraversal() {
	m_pRoot->InorderTraversal();
}
void LinkTree::PostorderTraversal() {
	m_pRoot->PostorderTraversal();
}