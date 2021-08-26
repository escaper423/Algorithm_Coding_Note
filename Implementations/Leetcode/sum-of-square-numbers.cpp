//problem URL: https://leetcode.com/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0)
            return true;
        
        for(int i = 1; i <= sqrt(c); i++){
            int target = c - (i * i);
            
            int l = 0;
            int r = sqrt(c);
            while(l <= r){
                int m = l + (r-l)/2;
                long long msq = m * m;
                if (target == msq){
                    return true;
                }
                else if (target < msq){
                    r = m - 1;
                }
                else if (target > msq){
                    l = m + 1;
                }
            }
        }
        return false;
    }
};
