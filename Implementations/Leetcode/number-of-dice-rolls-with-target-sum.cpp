//problem URL: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
private:
    int MOD = 1000000007;
public:
    long long getSome(vector<vector<long long>> &dp, int d, int f, int target, long long cur, int used){
        if (cur > target)
            return 0;
        
        if (used == d){
            return (cur == target)?1:0;
        }
        
        if (dp[cur][used] != -1){
            return dp[cur][used];
        }
        
        dp[cur][used] = 0;
        for(int i = 1; i <= f; i++){
            dp[cur][used] += getSome(dp,d,f,target,cur+i,used+1);  
            dp[cur][used] %= MOD;
        }
        
        return dp[cur][used]%MOD;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<long long>> dp(1001, vector<long long>(31, -1));
        getSome(dp, d, f, target, 0, 0);
        
        return dp[0][0]%MOD;
    }
};
