//problem URL: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
class Solution {
public:
    map<int,int> m;
    int getBoxIndex(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        for(int i = lowLimit; i <= highLimit; i++){
            int idx = getBoxIndex(i);
            m[idx]++;
            res = max(res,m[idx]);
        }
        
        return res;
    }
};
