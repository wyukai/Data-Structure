#ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h"

class  LinkList
{
public:
	~LinkList();
	LinkList();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node *pNode);
	int LocateElem(Node *pNode);
	bool PriorElem(Node *currentElem, Node *preElem);
	bool NextElem(Node *currentElem, Node *nextElem);
	bool ListInsert(int i, Node * e);
	bool ListDelete(int i, Node * e);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);

	void ListTraverse();

private:
	Node *m_pList;
	int m_iLength;
};






#endif 
