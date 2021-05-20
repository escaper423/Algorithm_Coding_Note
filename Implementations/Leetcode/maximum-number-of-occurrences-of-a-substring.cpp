//problem URL: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        int res = 0;
        unordered_map<string, int> m;
        
            for(int start = 0; start+minSize <= n; start++){
                bitset<26> letters(0);
                
                string t("");
                for(int end = start; end < start+minSize; end++){
                    letters.set(s[end] - 'a',1);
                    t += s[end];
                }
                if (letters.count() <= maxLetters){
                    m[t]++;
                    res = max(res, m[t]);
                }
            }
        
        
        return res;
    }
};
