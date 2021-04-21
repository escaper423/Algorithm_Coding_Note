//problem URL: https://leetcode.com/problems/find-the-duplicate-number/

//using binary-search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size();i++){
            int pos = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            if (pos < nums.size() - 1 && nums[pos+1] == nums[pos]){
                res = nums[pos];
                break;
            }
        }
        
        return res;
    }
};

//using hashmap
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        unordered_map <int, int> m;
        for(auto &it : nums){
            m[it]++;
        }
        
        for(auto &it : m){
            if (it.second > 1){
                res = it.first;   
            }
        }
        return res;
    }
};
