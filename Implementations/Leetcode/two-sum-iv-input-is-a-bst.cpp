//problem URL: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    vector<int> nums;
    
    void addNum(TreeNode* root){
        if(!root)
            return;
        
        addNum(root->left);
        nums.push_back(root->val);
        addNum(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        
        addNum(root);
        
        for(int i = 0; i < nums.size(); i++){
            int to_find = k - nums[i];
            int idx = lower_bound(nums.begin(), nums.end(), to_find) - nums.begin();
            if (i != idx && idx >= 0 && idx < nums.size() && nums[idx] == to_find){
                return true;
            }
        }
        return false;
    }
};
