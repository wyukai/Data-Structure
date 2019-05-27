#include <iostream>
#include <algorithm>
#include <vector>
#include "dp.h"
using namespace std;


/*
题目描述：最大连续乘积子数组
给定一个浮点数数组，任意取出数组中的若干连续的数相乘，请找出其中乘积最大
的子数组
*/
//解法1：蛮力查询 时间复杂度为O(n*n)
double Dp::MaxProductSubstring(double *a, int length) {
	double maxResult = a[0];
	for (int i = 0; i < length; i++)
	{
		//定义乘积和
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

//解法2：动态规划 状态转移方程：maxEnd=max(max(maxEnd*a[i],minEnd*a[i]),a[i]);
//时间复杂度为O(n)
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
题目描述：计算组合中乘积最大的一组
给定一个长度为n的整数数组，只允许用乘法，请计算任意n-1个数的组合中乘积最大的那一组。
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
////解法2：空间换时间来降低时间复杂度
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