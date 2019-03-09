#include "stackFunc.h"
#include "stack.h"
#include <iostream>
using namespace std;

//1. ¿®∫≈∆•≈‰
bool StackFunc::BrackerMatch(char *str) {
	MyStack<char> *p = new MyStack<char>(30);
	char e = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		switch (str[i]) {
		case '(':
			p->push(str[i]);
			p->stackTraverse(false);
			break;
		case '[': p->push(str[i]); break;
		case '{': p->push(str[i]); break;
		case ')':
			if (p->getTopElement() != '(')
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