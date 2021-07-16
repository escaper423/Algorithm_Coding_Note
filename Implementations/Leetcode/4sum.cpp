//problem URL: https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;
        
        for(int left = 0; left + 3 < n; left++){
            for(int right = left+3; right < n; right++){
                int l = left+1;
                int r = right-1;
                while(l < r){
                    int tmp = nums[left] + nums[l] + nums[r] + nums[right];
                    if (tmp == target){
                        s.insert({nums[left],nums[l],nums[r],nums[right]});
                        l++;
                    }
                    else if (tmp > target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        
        for(const auto &e : s){
            res.push_back(e);
        }
        
        return res;
        
    }
};
