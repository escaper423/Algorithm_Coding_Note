//problem URL:https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    
    long long getSum(int n){
        return ((long long)n*((long long)(n+1)))/2;
    }
    
    int arrangeCoins(int n) {
        int l = 1;
        int r = INT_MAX-1;
        int res = 0;
        
        if (n == 1)
            return 1;
        
        while(l <= r){
            int m = l + (r-l)/2;
            long long sum = getSum(m);
            if (sum <= n){
                l = m+1;
            }
            else{
                res = m;
                r = m-1;
            }
        }
        return res-1;
    }
};
