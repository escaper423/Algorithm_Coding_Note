//problem URL: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int idx = -1;
        
        vector<pair<int,int>> v;
        
        for(int i = 1; i < s.length(); i++){
            if (s[i] == s[i-1] && idx == -1){
                idx = i-1;
            }
            
            else if (s[i] != s[i-1] && idx != -1){
                int diff = i - idx;
                v.push_back({idx, diff});
                idx = -1;
            }
        }
        
        if (idx != -1){
            int diff = s.length() - idx;
            v.push_back({idx, diff});
        }
        
        for(const auto &it : v){
            int psum = 0;
            int maxval = 0;
            for(int i = it.first; i < it.first + it.second; i++){
                psum += cost[i];
                maxval = max(maxval, cost[i]);
            }
            res += (psum - maxval);
        }
        
        return res;
    }
};
