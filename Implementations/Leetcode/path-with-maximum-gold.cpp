problem URL: https://leetcode.com/problems/path-with-maximum-gold/
class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {-1,0,1,0};
    
public:
    bool isValid(int y, int x,vector<vector<int>>& grid){
        return y >= 0 && x >= 0 && y < grid.size() && x < grid[0].size();
    }
    
    int dfs(int y, int x, int cur, vector<vector<bool>> &visited, vector<vector<int>>& grid){
        visited[y][x] = true;
        
        int res = cur;
        for(int i = 0; i < 4; i++){
            int ny = y + dir_y[i];
            int nx = x + dir_x[i];
            
            if (isValid(ny,nx,grid) && grid[ny][nx] > 0 && visited[ny][nx] == false){
                res = max(res, dfs(ny,nx,cur + grid[ny][nx], visited, grid));
                visited[ny][nx] = false;
            }
        }
        return res;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int k = 0; k < grid[0].size(); k++){
                if (grid[i][k] > 0){
                    res = max(res , dfs(i,k,grid[i][k],visited,grid));
                    visited[i][k] = false;
                }
            }
        }
        return res;
    }
};
