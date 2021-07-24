//problem URL: https://leetcode.com/problems/binary-tree-pruning/
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
class Solution {
public:
    bool isContainOnes(TreeNode * root){
        if(!root)
            return false;
        
        bool res = root->val;
        res |= isContainOnes(root->left);
        res |= isContainOnes(root->right);
        return res;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return nullptr;
        
        if (!isContainOnes(root->left))
            root->left = nullptr;
        if (!isContainOnes(root->right))
            root->right = nullptr;
        
        pruneTree(root->left);
        pruneTree(root->right);
        
        if (root->left == nullptr && root->right == nullptr)
            return root->val?root:nullptr;
        else
            return root;
    }
};
