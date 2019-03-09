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
//1.2 冒泡排序的改进版：增加了对flag的判断，可以避免已经有排序的情况下的无意义循环判断
/*
当最好的情况，也就是排序的表本身就是有序的，只是进行了n-1次的比较，没有数据交换所以时间复杂度为O(n)
当最坏的情况，也就是排序为逆序的情况，需要比较1+2+3+...+(n-1)=n(n-1)/2次，并且需要作等数量级的移动，
所以时间复杂度为O(n*n);
*/
void MySort::BubbleSortUpdate(vector<int>& v) {
	int length = v.size();
	
	bool flag = true; //flag用来标记每一次冒泡的过程中是否存在数据交换

	for (int i = 0; i < length-1&&flag; i++)
	{
		flag = false;
		for (int j = 0; j < length-1-i; j++)
		{
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				flag = true;              //如果有数据交换，则flag为true
			}
		}
	}
}

//2. 快速排序
/*

*/
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

//3. 桶排序 时间复杂度O(M+N)，很快,但其空间利用率低
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

//4.简单选择排序  时间复杂度为O(n*n)
/*
无论最好最差的情况，其比较次数是一样多的，都为1+2+3+...+(n-1)=n(n-1)/2次
对于数据交换次数而言，最好的情况下（已排序状态），交换次数为0次，
最差的情况(初始状态为逆序)，交换次数为n-1次，所以最终的时间复杂度为O(n*n)
*/
void MySort::SelectSort(vector<int>& v) {
	int length = v.size();
	if (length <= 0) {
		return;
	}
	
	int i, j;
	for ( i= 0; i < length; i++) {
		int min = i;					//将当前下标定义为最小值下标
		for (j = i+1; j < length; j++)
		{
			if (v[min] > v[j]) {        //如果有小于当前最小值的值
				min = j;			    //将此值的下标赋给min
			}
		}
		if (min != i) {					//如果min!=i,说明找到了最小值，交换
			swap(v[i], v[min]);
		}
		
	}
}