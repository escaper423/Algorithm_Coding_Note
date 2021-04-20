//problem URL: https://leetcode.com/problems/slowest-key/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char tmp = keysPressed[0];
        int mx = releaseTimes[0];
        
        for(int i = 1; i < releaseTimes.size(); i++){
            int curLength = releaseTimes[i] - releaseTimes[i-1];
            if (curLength > mx || (curLength == mx && tmp < keysPressed[i]) ){
                tmp = keysPressed[i];
                mx = curLength;
            }
        }
        return tmp;
    }
};
