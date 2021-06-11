//problem URL: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for(int i = 0; i + 2 < s.length(); i++){
            for(int j = i + 2; j < s.length(); j++){
                string str = s.substr(i,j-i+1);
                int freq[26] = {0};
                int mx = 0, mn = 10000;
                
                for (auto &c : str){
                    freq[c - 'a']++;
                }
                for(int k =0 ; k< 26; k++){
                    if (freq[k] > 0)
                    {
                        mx = max(mx,freq[k]);
                        mn = min(mn,freq[k]);
                    }
                }
                if (mx > mn){
                    res += (mx - mn);
                }
            }
        }
        return res;
    }
};
