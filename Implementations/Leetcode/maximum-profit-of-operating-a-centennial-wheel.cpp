//problem URL: https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int accuCustomers = 0;
        int accuProfit = 0;
        int mxCost = 0;
        int res = -1, curMaxProfit = 0;
        int i = 0;
        for(; i < customers.size(); i++){
            accuCustomers += customers[i];
            
            int curBoarding = min(4,accuCustomers);
            accuCustomers -= curBoarding;
            accuProfit += (curBoarding * boardingCost) - runningCost;
            
            if (curMaxProfit < accuProfit){
                curMaxProfit = accuProfit;
                res = i+1;
            }
        }
        
        while(accuCustomers > 0){
            int curBoarding = min(4,accuCustomers);
            accuCustomers -= curBoarding;
            accuProfit += (curBoarding * boardingCost) - runningCost;
            
            if (curMaxProfit < accuProfit){
                curMaxProfit = accuProfit;
                res = i+1;
            }
            i++;
        }
        
        if (res == -1){
            return -1;
        }
        
        return res;
    }
};
