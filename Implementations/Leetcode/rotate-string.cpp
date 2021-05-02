//problem URL: https://leetcode.com/problems/rotate-string/
class Solution {
public:
    bool rotateString(string A, string B) {
        
        if (A.length() != B.length())
            return false;
        
        int n = A.length();
        int cnt = 0;
        
        if (n == 0)
            return true;
        
        while(cnt < n && A.compare(B)){
            char tmp = B.back();
            B.pop_back();
            B = tmp + B;
            cnt++;
        }
        return (cnt == n)?false:true;
        
    }
};
