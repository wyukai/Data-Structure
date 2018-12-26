#include "nodeTree.h"
#include <stdlib.h>
#include <iostream>;
using namespace std;

NodeTree::NodeTree() {
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;

}

NodeTree *NodeTree::SearchNode(int nodeIndex) {
	if (this->index == nodeIndex) {
		return this;
	}

	NodeTree *temp = NULL;
	if (this->pLChild!=NULL) {
		if (this->pLChild->index == nodeIndex) {
			return this->pLChild;
		}
		else
		{
			temp=this->pLChild->SearchNode(nodeIndex);
			if (temp!=NULL)
			{
				return temp;
			}
		}
	}
	if (this->pRChild != NULL) {
		if (this->pRChild->index == nodeIndex) {
			return this->pRChild;
		}
		else
		{
			temp=this->pRChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	return NULL;
}

void NodeTree::DeleteNode() {
	if (this->pLChild!=NULL)
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL) {
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL) {
		if (this->pParent->pLChild==this)
		{
			this->pParent->pLChild == NULL;
		}
		if (this->pParent->pRChild == this)
		{
			this->pParent->pRChild == NULL;
		}
	}

	delete this;
}
void NodeTree::PreorderTraversal() {
	cout <<this->index<<"¡ª¡ª"<< this->data << endl;
	if (this->pLChild!=NULL)
	{
		this->pLChild->PreorderTraversal();
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}

}
void NodeTree::InorderTraversal() {
	
	if (this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();
	}

	cout << this->index << "   " << this->data << endl;

	if (this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
}
void NodeTree::PostorderTraversal() {
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}

	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}

	cout << this->index << "   " << this->data << endl;
}