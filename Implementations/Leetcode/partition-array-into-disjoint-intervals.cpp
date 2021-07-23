//problem URL: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pmin(n, INT_MAX);
        vector<int> pmax(n, INT_MIN);

        pmax[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            pmax[i] = max(pmax[i-1], nums[i]);
        }
        
        pmin[n-1] = nums[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            pmin[i] = min(pmin[i+1], nums[i]);
        }
        
        for(int i = 0; i + 1 < n; i++){
            if (pmax[i] <= pmin[i+1]){
                return i + 1;
            }
        }
        return n;
    }
};
