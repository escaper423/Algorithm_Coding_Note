//problem URL: https://leetcode.com/problems/score-of-parentheses/
class Solution {
    
public:
    int helper(string &s, int &idx){
        int cur = 0;
        while(idx < s.length()){
            if (s[idx] == '(')
            {
                idx++;
                cur += helper(s,idx);
            }
            if (s[idx] == ')')
            {
                idx++;
                return (cur == 0)?1:cur * 2;
            }
        }
        return (cur == 0)?1:cur * 2;
    }
    int scoreOfParentheses(string s) {
        int idx = 0;
        int res = helper(s,idx);
        
        return res/2;
    }
};
