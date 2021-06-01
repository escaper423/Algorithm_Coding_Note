//problem URL: https://leetcode.com/problems/maximum-product-of-word-lengths/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int k = i+1; k < words.size(); k++){
                bitset<26> str1;
                bitset<26> str2;
                
                int len1 = words[i].length();
                int len2 = words[k].length();
                
                for(int j = 0; j < len1; j++){
                    str1.set(words[i][j] - 'a');
                }
                
                for(int j = 0; j < len2; j++){
                    str2.set(words[k][j] - 'a');
                }
                
                if ((str1 ^ str2).count() == str1.count() + str2.count()){
                    res = max(res, len1 * len2);
                }
            }
        }
        return res;
    }
};
