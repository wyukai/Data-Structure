#include "queue.h"
#include <iostream>
using namespace std;
MyQueue::MyQueue(int queueCapacity) {
	m_iQueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	//创建队列 (申请内存)
	m_pQueue = new Customer[m_iQueueCapacity];
}
MyQueue::~MyQueue() {
	delete[]m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::ClearQueue() {
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}
//成员函数中之所以加了const修饰，是为了保护对象的数据不会被修改，在函数中只能读取对象数据并不可以修改。
bool MyQueue::QueueEmpty()const {
	return m_iQueueLen == 0 ? true : false;
}

bool MyQueue::QueueFull()const {
	if (m_iQueueLen == m_iQueueCapacity) {
		return true;
	}
	else
	{
		return false;
	}
}

int MyQueue::QueueLength()const {
	return m_iQueueLen;
}

bool MyQueue::EnQueue(Customer element) {
	//判断队列是否已满
	if (QueueFull()) {
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail%m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}

bool MyQueue::DeQueue(Customer &element) {
	if (QueueEmpty()) {
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead%m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}

void MyQueue::QueueTraverse() {
	for (int i = m_iHead; i < m_iQueueLen+m_iHead; i++)
	{
		cout << "前面剩余顾客人数：：" << i - m_iHead << endl;
		m_pQueue[i%m_iQueueCapacity].printInfo();
	}
}