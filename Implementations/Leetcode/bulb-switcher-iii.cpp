//problem URL: https://leetcode.com/problems/bulb-switcher-iii/

/*
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        priority_queue<int,vector<int>, greater<int>> reserves;
        
        int cur_reached = 1;
        int res = 0;
        
        for(const auto & item: light){
            reserves.push(item);
            while(!reserves.empty() && reserves.top() == cur_reached){
                reserves.pop(); cur_reached++;
            }
            
            if(reserves.empty()){
                res++;
            }
        }
        
        return res;
    }
};
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        int cur_max = 1;
        int res = 0;
        
        for(int i = 0;i < light.size(); i++){
            cur_max = max(cur_max, light[i]);
            res+= (cur_max == i+1);
        }
        
        return res;
    }
};
