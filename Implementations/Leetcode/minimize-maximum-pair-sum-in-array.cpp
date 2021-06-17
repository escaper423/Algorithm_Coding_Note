//problem URL: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int r = ((n - 1)/2) + 1;
        int l = (n - 1)/2;
        
        while(l >= 0 && r < n){
            res = max(res, nums[l--] + nums[r++]);
        }
        return res;
    }
};
