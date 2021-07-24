//problem URL: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
class Solution {
public:
    string helper(string &s, int &idx){
        string cur = "";
        while(idx < s.length()){
            if (isalpha(s[idx])){
                cur += s[idx++];
            }
            
            if (s[idx] == '('){
                idx++;
                cur += helper(s, idx);
            }
            
            if(s[idx] == ')'){
                idx++;
                reverse(cur.begin(), cur.end());
                return cur;
            }
        }
        
        reverse(cur.begin(), cur.end());
        return cur;
    }
    
    string reverseParentheses(string s) {
        int idx = 0;
        string res = helper(s, idx);
        reverse(res.begin(), res.end());
        return res;
    }
};

