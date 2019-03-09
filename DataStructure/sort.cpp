#include <iostream>
#include "sort.h"

using namespace std;


//1. 冒泡排序 
/*
思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/
void MySort::BubbleSort(vector<int>& v) {
	int length = v.size();
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (v[j] > v[j + 1]) {
				int temp = v[j + 1];
				v[j + 1] = v[j];
				v[j]=temp;
			}
		}
	}
}

//2. 快速排序
void MySort::QuickSort(vector<int>& v, int left, int right) {
	//递归结束条件
	if (left > right) {
		return;
	}
	int first = left; //左侧下标
	int last = right; //右侧下标

	int key = v[first]; //设置基准

	while (first!=last)
	{
		//先从右往左找第一个比基准数小的值
		while (v[last]>=key&&first<last)
		{
			last--;
		}
		//在从左往右找第一个比基准数大的值
		while (first<last&&v[first]<=key)
		{	
			first++;
		}
		//当哨兵 first和last没有相遇时
		if (first < last) {
			int temp = v[right];
			v[last] = v[right];
			v[right] = temp;
		}
	}
	//哨兵相遇，基准数归位
	v[left] = v[first];
	v[first] = key;

	//基准数左侧递归
	QuickSort(v, left, first - 1);
	//基准数右侧递归
	QuickSort(v, first + 1, right);
}

//3. 桶排序
void MySort::BucketSort(vector<int>& v,int size) {
	//定义桶
	vector<int> bucket(size+1);
	for (int i = 0; i <= size; i++)
	{
		bucket[i] = 0;
	}

	for (int i = 0; i < v.size(); i++)
	{
		bucket[v[i]]++;
	}

	for (int i = 1; i <bucket.size(); i++)
	{
		for (int j = 0; j < bucket[i]; j++) {
			cout << i<<endl;
		}
	}
}