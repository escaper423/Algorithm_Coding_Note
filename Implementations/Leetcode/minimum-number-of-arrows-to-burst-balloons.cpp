//problem URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int needs = 1;
        sort(points.begin(), points.end());
        
        int pivot = points[0][1];
        
        for(int i = 1; i < points.size(); i++){
            if (points[i][0] > pivot){
                pivot = points[i][1];
                needs++;
            }
            else{
                pivot = min(pivot, points[i][1]);
            }
        }
        return needs;
    }
};
