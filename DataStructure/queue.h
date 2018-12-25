/*
环形队列
*/
#include "customer.h"
class MyQueue
{
public:
	
	MyQueue(int queueCapacity); //创建队列
	virtual ~MyQueue();        //销毁队列
	void ClearQueue();			//清空队列
	bool QueueEmpty() const;   //判断是否为空队列
	bool QueueFull() const;   //判断队列是否已满
	int QueueLength()const;    //队列长度
	bool EnQueue(Customer element); //新元素加入到队列
	bool DeQueue(Customer &element); //首元素弹出队列
	void QueueTraverse(); //遍历队列

private:
	Customer *m_pQueue;  //队列数组指针
	int m_iQueueLen; //队列元素个数
	int m_iQueueCapacity; //队列数据容量
	int m_iHead; //头索引
	int m_iTail; //尾索引
};


