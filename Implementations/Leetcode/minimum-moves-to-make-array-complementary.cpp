//problem URL: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
//reference: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/1306281/C%2B%2B-Easy-to-understand-solution-with-detailed-Explanation-or-O(n%2Blimit)
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> arr(2*limit+2,0);
        
        int n = nums.size() - 1;
        int res = INT_MAX;
        
        for(int i = 0; i < (n+1)/2; i++){
            int mn = min(nums[i], nums[n-i])+1;
            int mx = max(nums[i], nums[n-i])+limit+1;
            int old_val = nums[i] + nums[n-i];
            
            arr[2] += 2;
            arr[mn]--;
            arr[old_val]--;
            arr[old_val + 1]++;
            arr[mx]++;
        }
        
        for(int i = 2; i < 2*limit+2; i++){
            arr[i] += arr[i-1];
            res = min(res,arr[i]);
        }
        
        return res;
    }
};
