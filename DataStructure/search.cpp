#include "search.h"
#include <iostream>
using namespace std;

//1. ˳�����  ƽ��ʱ�临�Ӷȣ�O(n)���ռ临�Ӷ�O(1)
int  MySearch::SequentialSearch(vector<int> &v, int k) {
	if (v.size() <= 0) {
		return -1;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == k) {
			return i;
		}
	}
	//δ�ҵ�
	return -1;
}

//2.���ֲ���(��Ե������)
int  MySearch::BinarySearch(vector<int>&v,int k) {
	//�߽���
	if (v.size() <= 0) {
		return -1;
	}
	int left = 0;
	int right = v.size() - 1;
	while (left<=right)
	{	
		int mid = left + (right - left) / 2;
		if (v[mid] == k) {
			return mid;
		}
		else if (v[mid] > k) {
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

//2. ���ֲ��ң��ݹ鷽����
int  MySearch::BinarySearchReCursion(vector<int>&v, int k, int left,int right) {
	//�ݹ����ֹ����
	if (left>right) {
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (v[mid] == k) {
		return mid;
	}
	else if(v[mid]>k)
	{
		return BinarySearchReCursion(v, k, left, mid - 1);
	}
	else
	{
		return BinarySearchReCursion(v,k,mid+1,right);
	}
}