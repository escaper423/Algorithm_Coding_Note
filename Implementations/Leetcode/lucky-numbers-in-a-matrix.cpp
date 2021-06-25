//problem URL: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rowMin(matrix.size(),INT_MAX);
        vector<int> colMax(matrix[0].size(), INT_MIN);
        
        for(int r = 0; r < m; r++){
            int tmp = INT_MAX;
            for(int c = 0; c < n; c++){
                tmp = min(tmp,matrix[r][c]);        
                colMax[c] = max(colMax[c],matrix[r][c]);
            }
            rowMin[r] = tmp;
        }
        
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(rowMin[r] == colMax[c]){
                    res.push_back(matrix[r][c]);
                }
            }
        }
        
        return res;
    }
};
