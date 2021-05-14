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
 //problem URL: https://leetcode.com/problems/insert-into-a-binary-search-tree/
class Solution {
public:
    TreeNode* insertNode(TreeNode* root, int val){
        if (root == nullptr)
            return new TreeNode(val);
        
        if (root->val > val){
            root->left = insertNode(root->left, val);
        }
        else{
            root->right = insertNode(root->right, val);
        }
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = insertNode(root,val);
        return root;
        
    }
};
