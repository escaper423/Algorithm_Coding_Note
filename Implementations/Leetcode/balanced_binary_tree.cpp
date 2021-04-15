/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Problem URL: https://leetcode.com/problems/balanced-binary-tree/
class Solution {

	int helper(TreeNode* root, bool& b) {
		if (!root)
		{
			return 0;
		}

		int l = helper(root->left, b);
		int r = helper(root->right, b);

		if (abs(l - r) > 1) {
			b = false;
		}

		return 1 + max(l, r);
	}

public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;

		bool balance = true;
		helper(root, balance);
		return balance;

	}
};