//problem URL: https://leetcode.com/problems/check-if-a-string-can-break-another-string/
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int idx = 0;
        while(s1[idx] == s2[idx]) idx++;
        
        bool xg = s1[idx] > s2[idx];
        
        for(int i = idx+1; i < s1.length(); i++){
            if (s1[i] >= s2[i] && xg || s2[i] >= s1[i] && !xg)
                continue;
            return false;
        }
        
        return true;
    }
};
