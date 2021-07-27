//problem URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* makeTree(int l, int r, vector<int>&nums){
        if (l > r)
            return nullptr;
        if (l >= r)
            return new TreeNode(nums[l]);
        
        int m = l + (r-l)/2;
        TreeNode* ad = new TreeNode(nums[m]);
        ad->left = makeTree(l, m-1, nums);
        ad->right = makeTree(m+1,r,nums);
        return ad;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() - 1;
        TreeNode* root = makeTree(0,n,nums);
        return root;
    }
};
