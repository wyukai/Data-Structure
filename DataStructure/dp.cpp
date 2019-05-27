#include <iostream>
#include <algorithm>
#include <vector>
#include "dp.h"
using namespace std;


/*
��Ŀ��������������˻�������
����һ�����������飬����ȡ�������е���������������ˣ����ҳ����г˻����
��������
*/
//�ⷨ1��������ѯ ʱ�临�Ӷ�ΪO(n*n)
double Dp::MaxProductSubstring(double *a, int length) {
	double maxResult = a[0];
	for (int i = 0; i < length; i++)
	{
		//����˻���
		double product = 1;

		for (int j = i; j < length; j++)
		{
			product *= a[j];
			if (product > maxResult) {
				maxResult = product;
			}
		}
	}
	return maxResult;
}

//�ⷨ2����̬�滮 ״̬ת�Ʒ��̣�maxEnd=max(max(maxEnd*a[i],minEnd*a[i]),a[i]);
//ʱ�临�Ӷ�ΪO(n)
double Dp::MAxProductSubstring1(double *a, int length) {
	double maxResult = a[0];
	double maxEnd = a[0];
	double minEnd = a[0];
	for (int i = 1; i < length; i++)
	{
		maxEnd *= a[i];
		minEnd *= a[i];
		maxEnd = max(max(maxEnd,minEnd), a[i]);
		minEnd = min(min(maxEnd,minEnd), a[i]);
		maxResult = max(maxResult, maxEnd);
	}
	return maxResult;
}

/*
��Ŀ��������������г˻�����һ��
����һ������Ϊn���������飬ֻ�����ó˷������������n-1����������г˻�������һ�顣
*/
int Dp::MaxProductSub(int *a, int length) {

	int maxResult = 1;
	for (int i = 0; i < length; i++)
	{
		int maxEnd = 1;
		for (int j = 0; j < length; j++)
		{
			/*if (j == i) {
				maxEnd *= 1;
			}
			else
			{
				maxEnd *= a[j];
			}*/
			maxEnd *= ((i == j) ? 1 : a[j]);
		}
		if (maxResult < maxEnd) {
			maxResult = maxEnd;
		}
	}
	return maxResult;
}
////�ⷨ2���ռ任ʱ��������ʱ�临�Ӷ�
//int Dp::MaxProductSub1(int *a, int length) {
//
//	vector<int> pre;
//	vector<int> host;
//	pre[0] = 1;
//	host[0] = 1;
//	for (int i = 1; i < length; i++)
//	{
//		pre[i] = a[i-1] * pre[i];
//	}
//	for (int i = length-2; i >= 0; i--)
//	{
//		host[i] = a[i+1] * host[i];
//	}
//	vector<int> result;
//	result[0] = 1;
//	for (int i = 0; i < length; i++)
//	{
//		result[i] = pre[i-1] * host[i];
//	}
//}


//vector<int> Dp::GetLeastNumbersSolution(vector<int> a, int k) {
//	if (a.empty() || a.size()<k) {
//		return vector<int>();
//	}
//
//	vector<int> res(a.begin(), a.begin() + k);
//	make_heap(res.begin(), res.end());
//	for (int i = k; i<a.size(); i++) {
//		if (a[i]<res[0]) {
//			pop_heap(res.begin(), res.end());
//			res.pop_back();
//			res.push_back(a[i]);
//			push_heap(res.begin(), res.end());
//		}
//	}
//	sort_heap(res.begin(), res.end());
//	return res;
//}