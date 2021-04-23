//problem URL: https://leetcode.com/problems/perfect-squares/

//Using dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,10000);
        for(int num = 1; num * num <= n; num++){
            int squareNum = num * num;
            dp[squareNum] = 1;
            for(int i = squareNum + 1; i <= n; i++){
                dp[i] = min(dp[i-squareNum] + 1, dp[i]);
            }
        }
        
        return dp[n];
    }
};
//Using bfs
class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n+1,false);
        queue<pair<int,int>> q;
        visited[0] = true;
        q.push({0,0});
        int res = -1;
        while(!q.empty()){
            int cur = q.front().first; 
            int cnt = q.front().second;
            q.pop();
            if (cur == n){
                res = cnt;
                break;
            }
                
            for(int i = 0; i * i <= n; i++){
                int squareNum = i * i;
                if (cur + squareNum <= n && visited[cur + squareNum] == false){
                    q.push({cur + squareNum, cnt + 1});
                    visited[cur +squareNum] = true;
                }
            }
        }
        return res;
    }
};
