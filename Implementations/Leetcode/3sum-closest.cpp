//problem URL: https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = -1;
        int mn = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            int l = i+1; 
            int r = nums.size() - 1;    
            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                int diff = abs(target - sum);
                if (mn > diff){
                    mn = diff;
                    res = sum;
                }
                
                if (sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};
