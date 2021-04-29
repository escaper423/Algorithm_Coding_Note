//problem URL: https://leetcode.com/problems/bulb-switcher-iv/
class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        char lastChar = '0';
        
        for(auto &c : target){
            cnt += (lastChar != c);
            lastChar = c;
        }
        
        return cnt;
    }
};
