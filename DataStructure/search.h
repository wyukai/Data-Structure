#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
using namespace std;

class MySearch
{
public:
	//1. ˳����� ���������
	int SequentialSearch(vector<int>&v, int k);
	//���ֲ��ң��۰���ң���������������Ҫ������
	int BinarySearchReCursion(vector<int> &v,int k, int left, int right);
	int BinarySearch(vector<int>&v, int k);
private:

};



#endif // !SEARCH_H

