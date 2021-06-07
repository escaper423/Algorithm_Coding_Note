problem URL: https://leetcode.com/problems/non-overlapping-intervals/
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(),comp);
        
        int cend = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] < cend){
                res++;
            }
            else{
                cend = intervals[i][1];    
            }
        }
        return res;
    }
};
