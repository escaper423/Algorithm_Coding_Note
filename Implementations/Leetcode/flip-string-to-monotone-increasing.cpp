//problem URL: https://leetcode.com/problems/flip-string-to-monotone-increasing/
//reference: https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/1394750/C%2B%2B-Simple-and-Short-O(n)-Solution-With-Explanation
           //https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/1394780/Python-two-O(n)-solutions%3A-dp-and-accumulate-explained

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero_to_one = 0;
        int all_ones_to_zeros = 0;
        for(const auto &c : s){
            if(c == '1'){
                all_ones_to_zeros++;
            }
            if (c == '0'){
                zero_to_one++;
            }
            
            zero_to_one = min(zero_to_one, all_ones_to_zeros);
        }
        return zero_to_one;
    }
};
