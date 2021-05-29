//problem URL: https://leetcode.com/problems/longest-harmonious-subsequence/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> m;
        for(const auto &it : nums){
            m[it]++;
        }
        
        for(const auto &it : nums){
            if (m.find(it-1) != m.end()){
                res = max(res, m[it - 1] + m[it]);
            }
            if (m.find(it+1) != m.end()){
                res = max(res, m[it+ 1] + m[it]);
            }
        }
    
        return res;
    }
};
