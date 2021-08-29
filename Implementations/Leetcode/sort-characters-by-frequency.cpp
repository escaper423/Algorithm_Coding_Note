//problem URL: https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(const auto &c : s){
            freq[(int)c]++;
        }
        
        sort(s.begin(), s.end(), [freq] (auto c1, auto c2){
           if (freq[c1] > freq[c2])
               return true;
            else if (freq[c1] < freq[c2])
                return false;
            else{
                return c1 > c2;
            }
        });
        
        return s;
    }
};
