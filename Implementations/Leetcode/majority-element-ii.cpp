//problem URL: https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lastIdx = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]){
                int num = (i - 1) - lastIdx + 1;
                if (num > n/3){
                    res.push_back(nums[lastIdx]);
                }
                lastIdx = i;
            }
        }
        
        if ((n - 1) - lastIdx + 1 > n/3)
            res.push_back(nums[lastIdx]);
        
        
        return res;
    }
};
