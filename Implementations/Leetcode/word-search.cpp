//problem URL: https://leetcode.com/problems/word-search/
class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    
public:
    bool isValid(int y, int x, int m, int n){
        return y >= 0 && x >= 0 && y < m && x < n;
    }
    
    bool dfs(int y, int x, vector<vector<char>> &board, string target, string cur, int next, vector<vector<bool>>& visited){
        
        if (next == target.length()){
            return !target.compare(cur);
        }
        int m = board.size();
        int n = board[0].size();
        visited[y][x] = true;
        
        bool res = false;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (isValid(ny,nx,m,n) && target[next] == board[ny][nx] && visited[ny][nx] == false){
                res |= dfs(ny,nx,board,target,cur + board[ny][nx], next+1, visited);
                if (res) return true;
                visited[ny][nx] = false;
            }
        }
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<vector<bool>> visited(m, vector<bool>(n, false));       
                string init("");
                init += board[i][j];
                if(board[i][j] == word[0] && dfs(i,j,board,word,init,1,visited))
                    return true;
            }
        }
        return false;
    }
};
