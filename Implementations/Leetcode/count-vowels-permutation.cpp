//problem URL: https://leetcode.com/problems/count-vowels-permutation/
class Solution {
private:
    vector<vector<long long>> dp;
public:
    long long solve(int n, vector<vector<int>> &g, int pos, int cnt){
        if(n == cnt){
            return 1;
        }
        
        if (dp[cnt][pos] != -1){
            return dp[cnt][pos];
        }
        
        long long res = 0;
        for (const auto &v : g[pos]){
            res += solve(n, g, v, cnt+1);
        }
        
        return dp[cnt][pos] = res%1000000007;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> g(5, vector<int>());
        dp.resize(n, vector<long long>(5,-1));
        g[0].push_back(1);
        g[1].push_back(0); g[1].push_back(2);
        g[2].push_back(0); g[2].push_back(1); g[2].push_back(3); g[2].push_back(4);
        g[3].push_back(2); g[3].push_back(4);
        g[4].push_back(0);
        
        long long c = 0;
        for(int i = 0; i < 5; i++){
            c += solve(n, g, i, 1);    
        }
        
        int res = c%1000000007;
        return res;
    }
};
