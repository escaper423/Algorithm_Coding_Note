//problem URL: https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> rot(n, vector<char>(m));
        
        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){
                rot[i][k] = box[m-1-k][i];
            }
        }
        
        
        for(int r = n-1; r > 0; r--){
            for(int c = 0; c < m; c++){
                if (rot[r][c] == '.'){
                    int row = r;
                    while(row >= 0){
                        if(rot[row][c] == '#'){
                            rot[r][c] = '#';
                            rot[row][c] = '.';        
                            break;
                        }
                        else if (rot[row][c] == '*')
                            break;
                        row--;
                    }
                }
            }
        }
        
        return rot;
    }
};
