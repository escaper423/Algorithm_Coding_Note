//problem URL: https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:    
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        bool first_row_to_zero = false;
        for(int i = 0; i < r; i++){
            if (matrix[i][0] == 0)
                first_row_to_zero = true;
            
            for(int k = 1; k < c; k++){
                if (matrix[i][k] == 0){
                    matrix[i][0] = 0;
                    matrix[0][k] = 0;
                }
            }
        }
        
        for(int i = 1; i < r; i++){
            for(int k = 1; k < c; k++){
                if(matrix[i][0] == 0 || matrix[0][k] == 0){
                    matrix[i][k] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int i = 0; i < c; i++){
                matrix[0][i] = 0;
            }
        }
        
        if(first_row_to_zero){
            for(int i = 0; i < r; i++){
                matrix[i][0] = 0;
            }
        }
        
        
    }
};
