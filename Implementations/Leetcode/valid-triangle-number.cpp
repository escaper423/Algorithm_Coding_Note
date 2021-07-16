//problem URL: https://leetcode.com/problems/valid-triangle-number/
//reference: https://leetcode.com/problems/valid-triangle-number/discuss/1339340/C%2B%2BJavaPython-Two-Pointers-Picture-Explain-Clean-and-Concise-O(N2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int k = 2; k < n; k++){
            int l = 0;
            int r = k-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[k]){
                    res += r - l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        return res;
    }
};
