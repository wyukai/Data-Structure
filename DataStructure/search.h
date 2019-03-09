#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
using namespace std;

class MySearch
{
public:
	//1. 顺序查找 无序或有序
	int SequentialSearch(vector<int>&v, int k);
	//二分查找（折半查找）：有序，若无序，则要先排序
	int BinarySearchReCursion(vector<int> &v,int k, int left, int right);
	int BinarySearch(vector<int>&v, int k);
private:

};



#endif // !SEARCH_H

