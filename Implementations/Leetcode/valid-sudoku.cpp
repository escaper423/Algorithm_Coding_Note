//problem URL: https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValid(int r, int c, vector<vector<char>> & board){
        int ar = r/3;
        int ac = c/3;
        
        for(int i = 0; i < 9; i++){
            if (i != r && board[i][c] == board[r][c]){
                return false;
            }
            if (i != c && board[r][i] == board[r][c]){
                return false;
            }
        }
        
        for(int y = ar * 3; y < (ar * 3) + 3; y++){
            for(int x = ac * 3; x < (ac*3) + 3; x++){
                if ((r != y || c != x) && board[y][x] == board[r][c]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if (board[r][c] != '.'){
                    if (!isValid(r,c,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
