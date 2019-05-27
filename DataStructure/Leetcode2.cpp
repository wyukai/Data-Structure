#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//typedef struct ListNode ListNode;
void CreateLinkList(int n, ListNode* head) {
	ListNode *s = head;
	for (int i = 0; i <n; i++)
	{
		ListNode *p = new ListNode(0);
		cout << "输入链表的第：" << i + 1 << "个值" << endl;
		cin >> p->val;
		p->next = NULL;
		s->next = p;
		s = p;
	}
}
//两个数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode res(0), *p = &res;
	int sum = 0;
	while (l1 || l2 || sum)
	{
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		p->next = new ListNode(sum % 10);
		sum /= 10;
		p = p->next;
	}
	return res.next;
}

int main() {

	ListNode head1(0), *p1 = &head1;
	//head->val = 0;
	//head->next=NULL;
	ListNode head2(0), *p2 = &head2;
	CreateLinkList(3, p1);
	CreateLinkList(3, p2);

	/*while (p1 !=NULL)
	{
	cout << p1->val;
	p1 = p1->next;
	}
	while (p2 != NULL)
	{
	cout << p2->val;
	p2 = p2->next;
	}*/
	ListNode *result = addTwoNumbers(p1->next, p2->next);
	while (result)
	{
		cout << result->val;
		result = result->next;
	}
	system("pause");
	return 0;
}
