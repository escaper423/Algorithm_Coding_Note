//problem URL: https://leetcode.com/problems/average-waiting-time/
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        int cnt = 0;
        
        int lastTime = 0;
        int startTime = 0;
        double waitTime = 0.0;
        
        for(int i = 0; i < n; i++){
            lastTime = max(startTime,customers[i][0]) + customers[i][1];
            waitTime += lastTime - customers[i][0];
            startTime = lastTime;
            
        }
        
        return (waitTime / n);
    }
};
