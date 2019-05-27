#include <iostream>
#include <vector>
#include <algorithm>
#include <set>  //�Զ�����
#include <unordered_map>
using namespace std;

/*
����һ
(1)����һ��256ά��vector�����ϣ��ASCII���ܱ�ʾ256���ַ���
(2)��������������max_len�����洢����ظ��ִ��ĳ��ȣ�leftָ������ظ��Ӵ���ߵ���ʼλ��
(3)���������ַ���������ÿһ�����������ַ��������ϣ���и��ַ�����Ӧ��ֵΪ0��
	˵��û�����������ַ������ʱ��������ظ��Ӵ���i - left +����
	���У�������ظ��Ӵ����ұߵ�λ�ã�left������ߵ�λ��.
*/
int lengthOfLongestSubstring1(string s) {
	vector<int> dict(256, 0);
	int max_len = 0;
	int left = 0;
	for (int right = 0; right < s.size(); right++)
	{
		//�����ϣ���и��ַ�����Ӧ��ֵΪ0��˵��û�����������ַ�
		//����ϣ���е�ֵС��left���������ڴ�ʱ���ֹ��ظ����ַ���left��λ�ø���
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
������
�ѳ��ֹ����ַ�������set�У�����set��û�е��ַ��ͼ���set�в����½��res����������ظ��ģ������߿�ʼɾ�ַ���
ֱ��ɾ���ظ����ַ�ֹͣ��
*/
int lengthOfLongestSubstring2(string s) {
	set<char> t;
	int max_len = 0, left = 0, right = 0;
	while (right<s.size())
	{
		//��������ַ��Ͳ��뵽set��
		if (t.find(s[right]) == t.end()) {
			t.insert(s[right]);
			max_len = max(max_len, (int)t.size());
			right++;
		}
		//��������ظ��ģ������߿�ʼɾ�ַ���ֱ��ɾ���ظ����ַ�ֹͣ��
		else {
			t.erase(s[left]);
			left++;
		}
	}
	return max_len;
}

/*
������
ʹ����HashMap������ݽṹ�������ַ�����������λ��֮���ӳ�䣬�����������ͽⷨ1��ͬ��
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