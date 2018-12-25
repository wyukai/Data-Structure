#include <iostream>
#include <stdlib.h>

#include "stack.h"
#include "coordinate.h"
#include "list.h"
#include "linkList.h"

using namespace std;

//��������
#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16
#define DENARY 10


//��������
bool BrackerMatch(char *str);


//������
int main()
{

	/*ע�ͣ�  ��CTRL + K��Ȼ��CTRL + C

	ȡ��ע�ͣ� ��CTRL + K��Ȼ��CTRL + U*/

	//MyStack<int> *p = new MyStack<int>(30);

	
	//***************************************************
	/*1.����ת��  ʮ����ת�˽���*/
	 
	/*int N = 2016;
	int mod = 0;
	while (N != 0) {
		mod = N%HEXADECIMAL;
		p->push(mod);
		N = N / HEXADECIMAL;
	}
	
	//���ʮ�����Ƶ�ת������
	char num[] = "0123456789ABCDEF";

	int elem = 0;
	while (!p->stackEmpty())
	{
		p->pop(elem);
		cout << num[elem];
	}*/
	//****************************************************
	

	//*****************************************************
	/*
	2.ջӦ��--����ƥ��
	��������������һ�����ţ��ж������Ƿ�ƥ��
	*/
	/*char str[]= "([]})";
	if (BrackerMatch(str)) {
		cout << "���ųɹ�ƥ��" << endl;
	}
	else
	{
		cout << "���Ų�ƥ��" << endl;
	}*/
	//*****************************************************


	//*****************************************************

	////���Ա�˳���ģ���ຯ������
	//List<Coordinate> *list = new List<Coordinate>(10);
	//Coordinate e1 = (1, 2);
	//Coordinate e2 = (2, 3);
	//Coordinate e3 = (3, 4);
	//Coordinate e4 = (4, 5);
	//Coordinate e5 = (5, 6);

	//list->ListInsert(0, &e1);
	//list->ListInsert(1, &e2);
	//list->ListInsert(2, &e3);
	//list->ListInsert(3, &e4);
	//list->ListInsert(4, &e5);

	//list->ListTraverse();

	//Coordinate temp = (0,0);
	//list->GetElem(0, &temp);
	//cout << "temp" << temp << endl;

	//cout<<list->LocateElem(&temp)<<endl;
	//list->PriorElem(&e2, &temp);
	//cout <<"ǰ����"<< temp<<endl;
	//list->NextElem(&e2, &temp);
	//cout << "ǰ����" << temp << endl;

	//cout << "���Ա��ȣ�" << list->ListLength() << endl;
	//list->ClearList();
	//if (!list->ListEmpty()) {
	//	cout << "���Ա��ȣ�"<<list->ListLength()<<endl;
	//}
	//else {
	//	cout << "���Ա�Ϊ��" << endl;
	//}
	//*****************************************************

	

	//*****************************************************
	//��������
	/*Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;
	LinkList  *pList = new LinkList();

	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	pList->ListInsert(1, &node1);
	pList->ListTraverse();
	Node temp;
	pList->ListDelete(1, &temp);
	cout << "ɾ����Ԫ�أ�" << temp.data << endl << endl;

	pList->GetElem(0, &temp);
	cout << "ȡ����Ԫ�أ�" << temp.data << endl << endl;

	cout << "3����λ�ã�" << pList->LocateElem(&node1);



	delete pList;
	pList = NULL;*/
	//*****************************************************
	
	/*Person person1 = Person("xiaowang", "1111");*/
	Node node1;
	node1.data.name = "test1";
	node1.data.phone = "123456";
	
	Node node2;
	node2.data.name = "test2";
	node2.data.phone = "123456";

	LinkList *pList = new LinkList();

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListTraverse();

	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}

bool BrackerMatch(char *str) {
	MyStack<char> *p = new MyStack<char>(30);
	char e = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		switch(str[i]) {
			case '(':
				p->push(str[i]);
				p->stackTraverse(false);
				break;
			case '[': p->push(str[i]); break;
			case '{': p->push(str[i]); break;
			case ')':
				if (p->getTopElement()!='(')
				{	
					cout << p->getTopElement() << endl;
					return false;
				}
				else
				{	
					p->pop(e);
					break;
				}
			case ']':
				if (p->getTopElement() != '[')
				{
					return false;
				}
				else
				{

					p->pop(e);
					break;
				}
			case '}':
				if (p->getTopElement() != '}')
				{
					return false;
				}
				else
				{

					p->pop(e);
					break;
				}
			default:
				break;
		}
	}
	return p->stackEmpty();
}