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
 
 //problem URL: https://leetcode.com/problems/average-of-levels-in-binary-tree/
class Solution {
private:
    map<int, pair<double,int>> m;
    
public:
    void helper(int level, TreeNode* cur){
        if (cur == nullptr)
            return;
        
        m[level].first += cur->val;
        m[level].second += 1;
        
        helper(level + 1, cur->left);
        helper(level + 1, cur->right);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        helper(0, root);
        
        vector<double> res;
        for(auto &it : m){
            double d = it.second.first;
            int i = it.second.second;
            res.push_back(d/i);
        }
        return res;
    }
};
