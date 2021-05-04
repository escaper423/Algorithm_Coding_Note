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
 
//problem URL: https://leetcode.com/problems/diameter-of-binary-tree/submissions/
class Solution {
private:
    int res = 0;
public:
    
    int helper(TreeNode* root){
        if (root == nullptr)
            return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        res = max(res,l + r);
        return 1 + max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        helper(root);
        
        return res;
    }
};
