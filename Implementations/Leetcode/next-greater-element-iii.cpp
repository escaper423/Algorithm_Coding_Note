//problem URL: https://leetcode.com/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10)
            return -1;
        
        string s(to_string(n));
        string old = s;
        next_permutation(s.begin(), s.end());
        
        if(old.compare(s) >= 0)
            return -1;
        long long ret = stol(s);
        if (ret > INT_MAX)
            return -1;
        
        return stoi(s);
    }
};
