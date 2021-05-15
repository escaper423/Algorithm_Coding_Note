//problem URL: https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m;
        bool used[26] = {false};
        stringstream ss(s);
        string token;
        
        int i = 0;
        while(ss >> token){
            if ((m.find(token) == m.end() && used[pattern[i] - 'a'] == false) || m[token] == pattern[i]){
                m[token] = pattern[i];
                used[pattern[i] - 'a'] = true;
            }
    
            else{
                return false;
            }
            
            i++;
        }
        
        if (i < pattern.length())
            return false;
        
        return true;
    }
};
