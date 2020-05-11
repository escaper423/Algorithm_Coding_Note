#include <iostream>
#include <string>
#include <algorithm>

//problem URL : https://leetcode.com/problems/sum-root-to-leaf-numbers/

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res = 0; 

void dfs(TreeNode* root, string sum) {
	sum += to_string(root->val);
	if (root->left == nullptr && root->right == nullptr) {
		res += stoi(sum);
		return;
	}
	if (root->left) {
		dfs(root->left, sum);
	}
	if (root->right) {
		dfs(root->right, sum);
	}
}

int sumNumbers(TreeNode* root) {
	if (root == nullptr)
		return 0;
	dfs(root, "");
	return res;
}

int main() {
	TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	cout << sumNumbers(root);
	return 0;
}
