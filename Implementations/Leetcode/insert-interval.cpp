//problem URL: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        int s = intervals[0][0];
        int e = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if (e >= intervals[i][0]){
                e = max(e, intervals[i][1]);
            }
            else{
                res.push_back(vector{s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        
        res.push_back(vector{s,e});
        
        return res;
    }
};
