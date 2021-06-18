//problem URL: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        int cnt = 1;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++){
            
            while(cnt < nums[i]){
                res.push_back(cnt++);
            }
            
            if (cnt == nums[i]){
                cnt++;
            }
        }
        
        while(cnt <= nums.size()){
            res.push_back(cnt++);
        }

        return res;
    }
};
