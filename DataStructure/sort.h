#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;
class MySort
{
public:
	
	void BubbleSort(vector<int>& v);
	void QuickSort(vector<int>& v,int low,int high);
	void BucketSort(vector<int>& v,int size);
private:

};


#endif // !SORT_H
#pragma once
