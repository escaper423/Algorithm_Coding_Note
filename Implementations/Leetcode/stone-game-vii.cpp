//problemURL: https://leetcode.com/problems/stone-game-vii/

class Solution {
public:
    int dp[1010][1010];
    
    int solve(int s, int e, vector<int>& stones, int sum){
        if (s >= e){
            return dp[s][e] = 0;
        }    
        
        if (dp[s][e] != -1)
            return dp[s][e];
        
        dp[s][e] = max(sum - stones[s] - solve(s+1,e,stones,sum - stones[s]),
                       sum - stones[e] - solve(s,e-1,stones,sum - stones[e]));
        
        return dp[s][e];
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n = stones.size();
        int sum = 0;
        for(int i = 0; i < n;i++)
            sum += stones[i];
        
        int res = solve(0,n-1,stones,sum);
        return res;
    }
};
