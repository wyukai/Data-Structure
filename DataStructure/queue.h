/*
���ζ���
*/
#include "customer.h"
class MyQueue
{
public:
	
	MyQueue(int queueCapacity); //��������
	virtual ~MyQueue();        //���ٶ���
	void ClearQueue();			//��ն���
	bool QueueEmpty() const;   //�ж��Ƿ�Ϊ�ն���
	bool QueueFull() const;   //�ж϶����Ƿ�����
	int QueueLength()const;    //���г���
	bool EnQueue(Customer element); //��Ԫ�ؼ��뵽����
	bool DeQueue(Customer &element); //��Ԫ�ص�������
	void QueueTraverse(); //��������

private:
	Customer *m_pQueue;  //��������ָ��
	int m_iQueueLen; //����Ԫ�ظ���
	int m_iQueueCapacity; //������������
	int m_iHead; //ͷ����
	int m_iTail; //β����
};


