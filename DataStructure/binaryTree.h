#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int length = sequence.size();
		if (length == 0) {
			return false;
		}
		//�����������ĸ��ڵ�Ϊ������������һ�����
		int root = sequence[length - 1];

		//�ҵ���һ�����ڸ��ڵ�Ľ������i
		int i;
		vector<int> left;  //���������
		for (i = 0; i<length - 1; i++) {
			if (sequence[i]>root) {
				break;
			}
			left.push_back(sequence[i]);
		}
		

		//�������������������Ľ�㶼���ڸ��ڵ�
		int j = i;
		vector<int> right;  //���������
		for (; j<length - 1; j++) {
			if (sequence[j]<root) {
				return false;
			}
			right.push_back(sequence[j]);
		}

	

		return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);

	}
};
//
//int main() {
//	
//}
