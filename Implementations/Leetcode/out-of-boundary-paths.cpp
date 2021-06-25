//problem URL: https://leetcode.com/problems/out-of-boundary-paths/
class Solution {
public:
    int MOD = 1000000007;
    int getNumPaths(int r, int c, int N, int i, int j, vector<vector<vector<int>>> &D){
        if (i < 0 || i >= r || j < 0 || j >= c)
            return 1;
        
        if (N == 0)
            return 0;
        
        if (D[i][j][N] != -1)
            return D[i][j][N];
        
        int res = 0;
        
        res = res % MOD + getNumPaths(r,c,N-1,i+1,j,D) % MOD;
        res = res % MOD + getNumPaths(r,c,N-1,i,j+1,D) % MOD;
        res = res % MOD + getNumPaths(r,c,N-1,i-1,j,D) % MOD;
        res = res % MOD + getNumPaths(r,c,N-1,i,j-1,D) % MOD;
            
        return D[i][j][N] = res;
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> D(m, vector<vector<int>>(n, vector<int>(N+1,-1)));
        int res = getNumPaths (m,n,N,i,j,D);
        return res % MOD;
    }
};
