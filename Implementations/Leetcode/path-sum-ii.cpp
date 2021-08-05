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
 //problem URL: https://leetcode.com/problems/path-sum-ii/
class Solution {
private:
    vector<vector<int>> res;
public:
    void searchPath(TreeNode *root, int target, vector<int> v, int cur){
        int val = cur + root->val;
        v.push_back(root->val);
        
        if (val == target && (!root->left && !root->right)){
            res.push_back(v);
        }
        
        if(root->left){
            searchPath(root->left, target, v, val);
        }
        if(root->right){
            searchPath(root->right, target, v, val);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return res;
        
        searchPath(root, targetSum, vector<int>(), 0);
        return res;
    }
};
