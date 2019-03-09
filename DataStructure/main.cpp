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
//主函数
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
	cout << "\n快速排序的运行时间为：" << totalTime << "秒。" << endl;

	/*
	C++计时方法：C++中的计时函数是clock()，而与其相关的数据类型是clock_t（头文件是time.h）。函数定义原型为：clock_t clock(void);
	clock_t start, finish;
	double totaltime;
	start = clock();
	......//待执行程序
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	*/
	



	system("pause");
	return 0;
}
