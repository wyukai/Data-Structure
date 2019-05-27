#include <iostream>
using namespace std;
#include <vector>


bool checkPossibility(vector<int>& nums){
	int count = 0;
	for (int i = 0; i < nums.size() - 1 && count <= 1; i++) {
		if (nums[i] > nums[i + 1]) {
			count++;
			if (i - 1 < 0 || nums[i - 1] <= nums[i + 1]) nums[i] = nums[i + 1];
			else nums[i + 1] = nums[i];
		}
	}
	return count <= 1;
};

int main()
{
	vector<int> vec;
	int temp = 0;
	cout << "输入整数，以任意字母结束：" << endl;
	while (cin >> temp)
	{
		vec.push_back(temp); //填充数据
	}
	bool result = checkPossibility(vec);
	cout << result << endl;
	return 0;
}
