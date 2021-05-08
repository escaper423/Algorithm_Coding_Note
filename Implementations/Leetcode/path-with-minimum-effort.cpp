//problem URL: https://leetcode.com/problems/path-with-minimum-effort/
class Solution {
public:
    int dir_y[4] = {1,0,-1,0};
    int dir_x[4] = {0,1,0,-1};
    
    bool isValid(int r, int c, int height, int width){
        return (r >= 0 && c >= 0 && r < height && c < width);
    }
    
    bool findPath(int row ,int col, int maxCost, vector<vector<int>>& heights, vector<vector<bool>> &visited){
        if (row == heights.size() - 1 && col == heights[0].size() - 1){
            return true;
        }
        visited[row][col] = true;
        
        for(int i = 0; i < 4; i++){
            int ny = row + dir_y[i];
            int nx = col + dir_x[i];
            if(isValid(ny,nx,heights.size(), heights[0].size())
               && abs(heights[row][col] - heights[ny][nx]) <= maxCost 
               && visited[ny][nx] == false)
            {
                if (findPath(ny,nx,maxCost,heights,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        int res = INT_MAX;
        
        int l = 0;
        int r = 1e9;
        
        while(l <= r){
            int maxCost = l + (r-l)/2;
            vector<vector<bool>> visited(row, vector<bool>(col,false));
            int g = findPath(0,0,maxCost,heights,visited);
            if(g){
                res = maxCost;
                r = maxCost - 1;
            }
            else{
                l = maxCost + 1;
            }
        }
        
        return res;
    }
};
