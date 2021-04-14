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
    //problem URL: https://leetcode.com/problems/subtree-of-another-tree/
    bool isIdentical(TreeNode* s, TreeNode* t){
        if (s == nullptr && t == nullptr)
            return true;
        
        if (t == nullptr || s == nullptr)
            return false;
        
        return s->val == t->val && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
    }
    
    bool traverse(TreeNode* s, TreeNode* t){
        if (s == nullptr)
            return false;
        return isIdentical(s,t) || traverse(s->left,t) || traverse(s->right,t);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s, t);    
    }
};
