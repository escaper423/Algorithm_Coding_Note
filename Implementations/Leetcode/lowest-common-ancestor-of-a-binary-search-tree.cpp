//problem URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mx = max(p->val, q->val);
        int mn = min(p->val, q->val);
        
        if (root->val > mn && root->val < mx){
            return root;
        }
        
        if(root->val > mx){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if (root->val < mn){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if (root->val == mn || root->val == mx){
            return root;
        }
        else return nullptr;
    }
};
