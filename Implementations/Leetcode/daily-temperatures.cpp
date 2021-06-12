//problem URL: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        
        stack<pair<int,int>> s;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            if (i == temperatures.size() - 1){
                res.push_back(0);
                s.push({temperatures[i],i});
            }
            
            else{
                while(!s.empty() && s.top().first <= temperatures[i]){
                    s.pop();
                    
                    if (s.empty()){ 
                        break;
                    }
                }
                res.push_back(s.empty()?0:s.top().second - i);
                s.push({temperatures[i],i});
            }    
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
