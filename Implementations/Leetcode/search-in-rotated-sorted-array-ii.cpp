//problem URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        int pivot = -1;
        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        if (nums.size() == 1)
            return nums[0] == target;
        
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1])
            {
                pivot = i+1;
                break;
            }
        }
        if(pivot == -1){
            int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            return (idx == nums.size())?false:nums[idx] == target;
        }
        
        
        int first = lower_bound(nums.begin(), nums.begin() + pivot - 1, target) - nums.begin();
        int second = lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();
        
        if (nums[first] == target || (second < nums.size() && nums[second] == target))
            return true;
        
        return false;
    }
};
