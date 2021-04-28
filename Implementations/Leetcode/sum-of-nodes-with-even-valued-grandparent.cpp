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
 
 //problem URL: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
class Solution {
public:
    int dfs(TreeNode* parent, TreeNode* cur){
        if (cur == nullptr)
            return 0;
        
        int res = 0;
        res += dfs(cur, cur->right);
        res += dfs(cur, cur->left);
        
        if (parent != nullptr){
            
            if (cur->right){
                res += cur->right->val * (parent->val % 2 == 0);
            }
        
            if (cur->left){
                res += cur->left->val * (parent->val % 2 == 0);
            }   
        }
        return res;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        return res = dfs(nullptr, root);
        
    }
};
