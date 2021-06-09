//problem URL: https://leetcode.com/problems/maximum-binary-tree/
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r){
        if (l > r)
            return nullptr;
        
        int pivot = l;
        
        for(int i = l+1; i <= r; i++){
            if (nums[pivot] < nums[i]){
                pivot = i;
            }
        }
        TreeNode *root = new TreeNode(nums[pivot]);

        root->left = helper(nums, l, pivot-1);
        root->right = helper(nums, pivot+1, r);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
        
    }
};
