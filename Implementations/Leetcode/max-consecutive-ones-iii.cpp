//problem URL: https://leetcode.com/problems/max-consecutive-ones-iii/
//reference: https://leetcode.com/problems/max-consecutive-ones-iii/discuss/1304346/Simple-Solution-w-Explanation-or-Sliding-Window-Approach-with-Comments
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int l = 0;
        int r = 0;
        for(;r < nums.size(); r++){
            if (nums[r] == 0){
                if (k == 0){
                    while(nums[l++] != 0);
                }
                else{
                    k--;
                }
            }
            res = max(res, r - l + 1);
            
        }
        return res;
    }
};
