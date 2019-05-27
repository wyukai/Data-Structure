#include <iostream>
#include <vector>
#include <algorithm>
#include <set>  //自动排序
#include <unordered_map>
using namespace std;

/*
方法一
(1)建立一个256维的vector代表哈希表（ASCII表功能表示256个字符）
(2)定义两个变量，max_len用来存储最长无重复字串的长度，left指向该无重复子串左边的起始位置
(3)遍历整个字符串，对于每一个遍历到的字符，如果哈希表中该字符串对应的值为0，
	说明没有遇到过该字符，则此时计算最长无重复子串，i - left +１，
	其中ｉ是最长无重复子串最右边的位置，left是最左边的位置.
*/
int lengthOfLongestSubstring1(string s) {
	vector<int> dict(256, 0);
	int max_len = 0;
	int left = 0;
	for (int right = 0; right < s.size(); right++)
	{
		//如果哈希表中该字符串对应的值为0，说明没有遇到过该字符
		//当哈希表中的值小于left，这是由于此时出现过重复的字符，left的位置更新
		if (dict[s[right]]==0||dict[s[right]] < left) {
			max_len = max(max_len, right - left + 1);
		}
		else
		{
			left = dict[s[right]]+1;
		}
		dict[s[right]] = right;
	}
	return max_len;
}
/*
方法二
把出现过的字符都放入set中，遇到set中没有的字符就加入set中并更新结果res，如果遇到重复的，则从左边开始删字符，
直到删到重复的字符停止。
*/
int lengthOfLongestSubstring2(string s) {
	set<char> t;
	int max_len = 0, left = 0, right = 0;
	while (right<s.size())
	{
		//如果是新字符就插入到set中
		if (t.find(s[right]) == t.end()) {
			t.insert(s[right]);
			max_len = max(max_len, (int)t.size());
			right++;
		}
		//如果遇到重复的，则从左边开始删字符，直到删到重复的字符停止。
		else {
			t.erase(s[left]);
			left++;
		}
	}
	return max_len;
}

/*
方法三
使用了HashMap这个数据结构来建立字符和其最后出现位置之间的映射，其他操作均和解法1相同。
*/
int lengthOfLongestSubstring3(string s) {
	unordered_map<char, int> m;
	int max_len = 0, left = 0;
	for (int right = 0; right < s.size(); right++)
	{
		left = max(left, m[s[right]]);
		m[s[right]] = right+1;
		max_len = max(max_len,right-left+1);
	}
	return max_len;
}
int main() {
	string s("aba");
	int max_len = lengthOfLongestSubstring3(s);
	cout << "max_len:" << max_len;
	system("pause");
	return 0;
}