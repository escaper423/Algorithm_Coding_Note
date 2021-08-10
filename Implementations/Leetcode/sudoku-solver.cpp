//problem URL: https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool isUniqueV(vector<vector<char>>& board, int x, char val){
        bool isdup = false;
        for(int i = 0; i < 9; i++){
            if (board[i][x] == val){
                if (isdup){
                    return false;
                }
                else{
                    isdup = true;
                }
            }
        }
        return true;
    }
    
    bool isUniqueH(vector<vector<char>>& board, int y, char val){
        bool isdup = false;
        for(int i = 0; i < 9; i++){
            if (board[y][i] == val){
                if (isdup){
                    return false;
                }
                else{
                    isdup = true;
                }
            }
        }
        return true;
    }
    
    bool isUniqueA(vector<vector<char>>& board, int x, int y, char val){
        int ax = x/3;
        int ay = y/3;
        bool isdup = false;
        for(int i = ay * 3; i < (ay * 3) + 3; i++){
            for(int k = ax * 3; k < (ax * 3) + 3; k++){
                if(board[i][k] == val)
                {
                    if (isdup){
                        return false;
                    }
                    else{
                        isdup = true;
                    }
                }
            }
        }
        return true;
    }
    
    
    bool solve(vector<pair<int,int>> &points, vector<vector<char>> & board, int cur){
        if(cur == points.size())
            return true;
        
        int y = points[cur].first;
        int x = points[cur].second;
        
        for(int i = 1; i <= 9; i++){
            board[y][x] = i + '0';
            if(isUniqueV(board,x,board[y][x]) && isUniqueH(board,y,board[y][x]) && isUniqueA(board,x,y,board[y][x])){
                if(solve(points,board, cur+1))
                    return true;
            }
            board[y][x] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<pair<int,int>> points;
        vector<vector<int>> visited(n, vector<int>(n,0));
        for(int i = 0; i < n; i++){
            for(int k = 0 ; k < n; k++){
                if (board[i][k] == '.'){
                    points.push_back({i,k});
                }
            }
        }
        
        solve(points, board, 0);
    }
};
