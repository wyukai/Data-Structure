#include "search.h"
#include <iostream>
using namespace std;

//1. 顺序查找  平均时间复杂度：O(n)；空间复杂度O(1)
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
	//未找到
	return -1;
}

//2.二分查找(针对递增情况)
int  MySearch::BinarySearch(vector<int>&v,int k) {
	//边界检查
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

//2. 二分查找（递归方法）
int  MySearch::BinarySearchReCursion(vector<int>&v, int k, int left,int right) {
	//递归的终止条件
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