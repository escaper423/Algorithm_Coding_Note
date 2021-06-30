/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //problem URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
private:
    TreeNode *res = nullptr;
    
public:
    bool f(TreeNode* root, TreeNode* v){
        if (!root)
            return false;
        
        if(root->val == v->val)
            return true;
        
        return f(root->left, v) || f(root->right, v);
    }
    
    void solve(TreeNode *root, TreeNode *p, TreeNode *q){
        if (!root)
            return;
        
        solve(root->left,p,q);
        solve(root->right,p,q);
        
        bool pFind = f(root, p);
        bool qFind = f(root, q);
        
        if (pFind && qFind && res == nullptr){
            res = root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return res;
    }
};
