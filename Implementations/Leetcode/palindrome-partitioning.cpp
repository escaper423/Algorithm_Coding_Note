//problem URL: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string s){
        int n = s.length();
        if (n == 1)
            return true;
        if (n == 2)
            return s[0] == s[1];
        
        int l = 0, r = n-1;
        
        while(l < r && s[l] == s[r]){
            l++; r--;
        }
        
        return (l >= r);
    }
    
    void dfs(string &s, int start, vector<string>& tmp){
        if (start >= s.length()){
            res.push_back(tmp);
        }
        
        for(int i = start; i < s.length(); i++){
            string str = s.substr(start, i - start + 1);
            if (isPalindrome(str)){
                tmp.push_back(str);
                dfs(s,i+1,tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> tmp;
        dfs(s,0,tmp);
        
        return res;
    }
};
