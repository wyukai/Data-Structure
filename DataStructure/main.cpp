#include <iostream>
#include <stdlib.h>

#include "stack.h"
#include "coordinate.h"
#include <iostream>
using namespace std;
#include <vector>
#include <time.h>
#include "search.h"
#include "sort.h"
//������
int main()
{

	clock_t start, finish;
	double totalTime;
	start = clock();

	MySearch search;
	MySort sort;
	vector<int> v= {3, 2, 1, 5, 4, 6};
	sort.BucketSort(v,6);
	
	
	finish = clock();
	totalTime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n�������������ʱ��Ϊ��" << totalTime << "�롣" << endl;

	/*
	C++��ʱ������C++�еļ�ʱ������clock()����������ص�����������clock_t��ͷ�ļ���time.h������������ԭ��Ϊ��clock_t clock(void);
	clock_t start, finish;
	double totaltime;
	start = clock();
	......//��ִ�г���
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n�˳��������ʱ��Ϊ" << totaltime << "�룡" << endl;
	*/
	



	system("pause");
	return 0;
}
