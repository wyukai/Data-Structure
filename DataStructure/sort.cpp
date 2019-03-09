#include <iostream>
#include "sort.h"

using namespace std;


//1. ð������ 
/*
˼·��
1. �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2. ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
3. ������е�Ԫ���ظ����ϵĲ��裬�������һ����
4. ����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
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

//2. ��������
void MySort::QuickSort(vector<int>& v, int left, int right) {
	//�ݹ��������
	if (left > right) {
		return;
	}
	int first = left; //����±�
	int last = right; //�Ҳ��±�

	int key = v[first]; //���û�׼

	while (first!=last)
	{
		//�ȴ��������ҵ�һ���Ȼ�׼��С��ֵ
		while (v[last]>=key&&first<last)
		{
			last--;
		}
		//�ڴ��������ҵ�һ���Ȼ�׼�����ֵ
		while (first<last&&v[first]<=key)
		{	
			first++;
		}
		//���ڱ� first��lastû������ʱ
		if (first < last) {
			int temp = v[right];
			v[last] = v[right];
			v[right] = temp;
		}
	}
	//�ڱ���������׼����λ
	v[left] = v[first];
	v[first] = key;

	//��׼�����ݹ�
	QuickSort(v, left, first - 1);
	//��׼���Ҳ�ݹ�
	QuickSort(v, first + 1, right);
}

//3. Ͱ����
void MySort::BucketSort(vector<int>& v,int size) {
	//����Ͱ
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