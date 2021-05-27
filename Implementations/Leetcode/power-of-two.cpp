//problem URL: https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n % 2 == 0 && n > 1){
            n >>= 1;
        }
        
        return (n == 1);
    }
};
