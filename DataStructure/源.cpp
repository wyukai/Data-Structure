#include <iostream>
#include <stdlib.h>

#include "stack.h"
#include "coordinate.h"
#include "list.h"
#include "linkList.h"

using namespace std;

//常量定义
#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16
#define DENARY 10


//函数声明
bool BrackerMatch(char *str);


//主函数
int main()
{

	/*注释：  先CTRL + K，然后CTRL + C

	取消注释： 先CTRL + K，然后CTRL + U*/

	//MyStack<int> *p = new MyStack<int>(30);

	
	//***************************************************
	/*1.进制转换  十进制转八进制*/
	 
	/*int N = 2016;
	int mod = 0;
	while (N != 0) {
		mod = N%HEXADECIMAL;
		p->push(mod);
		N = N / HEXADECIMAL;
	}
	
	//解决十六进制的转换问题
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
	2.栈应用--括号匹配
	描述：任意输入一组括号，判断括号是否匹配
	*/
	/*char str[]= "([]})";
	if (BrackerMatch(str)) {
		cout << "括号成功匹配" << endl;
	}
	else
	{
		cout << "括号不匹配" << endl;
	}*/
	//*****************************************************


	//*****************************************************

	////线性表《顺序表》模板类函数测试
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
	//cout <<"前驱："<< temp<<endl;
	//list->NextElem(&e2, &temp);
	//cout << "前驱：" << temp << endl;

	//cout << "线性表长度：" << list->ListLength() << endl;
	//list->ClearList();
	//if (!list->ListEmpty()) {
	//	cout << "线性表长度："<<list->ListLength()<<endl;
	//}
	//else {
	//	cout << "线性表为空" << endl;
	//}
	//*****************************************************

	

	//*****************************************************
	//线性链表
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
	cout << "删除的元素：" << temp.data << endl << endl;

	pList->GetElem(0, &temp);
	cout << "取到的元素：" << temp.data << endl << endl;

	cout << "3所在位置：" << pList->LocateElem(&node1);



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