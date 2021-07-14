//problem URL: https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int getPeakIndex(vector<int>& nums, int l, int r){
        if (l >= r){
            return l;
        }
        
        int m = l + (r - l)/2;
        int left = getPeakIndex(nums,l,m);
        int right = getPeakIndex(nums,m+1,r);
        
        return (nums[left] > nums[right])?left:right;
    }
    
    int findPeakElement(vector<int>& nums) {
        return getPeakIndex(nums,0,nums.size() - 1);
    }
};
