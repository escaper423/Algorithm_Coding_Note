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
 
 problem URL: https://leetcode.com/problems/trim-a-binary-search-tree/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return nullptr;
        
        TreeNode* l = trimBST(root->left, low, high);
        TreeNode* r = trimBST(root->right, low, high);
        
        if (root->val < low)
            return r;
        if (root->val > high)
            return l;
        
        root->right = r;
        root->left = l;
        
        return root;
    }
};
