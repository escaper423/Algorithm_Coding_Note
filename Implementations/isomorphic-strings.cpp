class Solution {
    //problem URL: https://leetcode.com/problems/isomorphic-strings/
public:
    unordered_map<char,char> m;
    unordered_set<char> b;
    bool isIsomorphic(string s, string t) {
        
        for(int i = 0; i < s.length(); i++){
            if (m.find(s[i]) == m.end()){
                if (b.find(t[i]) == b.end()){
                    m[s[i]] = t[i];    
                    b.insert(t[i]);
                }
                
                else if (b.find(t[i]) != b.end()){
                    return false;
                }
            }
            else if (m[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};
