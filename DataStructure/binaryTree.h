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
		//二叉搜索树的根节点为后序遍历的最后一个结点
		int root = sequence[length - 1];

		//找到第一个大于根节点的结点索引i
		int i;
		vector<int> left;  //左子树结点
		for (i = 0; i<length - 1; i++) {
			if (sequence[i]>root) {
				break;
			}
			left.push_back(sequence[i]);
		}
		

		//二叉搜索树的右子树的结点都大于根节点
		int j = i;
		vector<int> right;  //右子树结点
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
