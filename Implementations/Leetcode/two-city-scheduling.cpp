//problem URL: https://leetcode.com/problems/two-city-scheduling/
class Solution {
public:
    static int comp(vector<int> a, vector<int> b){
        return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        int n = costs.size();
        sort(costs.begin(), costs.end(), comp);
        
        int as=0, bs=0;
        
        for(int i = 0; i < n; i++){
            if (as >= (n >> 1)){
                bs++;
                sum += costs[i][1];
                continue;
            }
            
            if (bs >= (n >> 1)){
                as++;
                sum += costs[i][0];
                continue;
            }
            if (costs[i][0] < costs[i][1]){
                as++;
                sum += costs[i][0];
            }
            if (costs[i][0] > costs[i][1]){
                bs++;
                sum += costs[i][1];
            }
            if (costs[i][0] == costs[i][1]){
                if (as < bs){
                    as++;
                    sum += costs[i][0];
                }
                else{
                    bs++;
                    sum += costs[i][1];
                }
            }
        }
        
        return sum;
    }
};
