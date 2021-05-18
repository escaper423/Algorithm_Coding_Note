//problem URL: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
class Solution {
private:
    int res = 0;    
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> max_right(n, 0);
        
        for(int r = 0; r < n; r++){
            int idx = n - 1;
            int trailing_zeros = 0;
            while(idx >= 0 && !grid[r][idx]){
                idx--;
                trailing_zeros++;
            }
            max_right[r] = max(0,n - 1 - trailing_zeros);
        }
        
        
        for(int i = 0; i < n; i++){
            int num_swaps_needed = 0;
            
            for(num_swaps_needed = 0; num_swaps_needed < n - i; num_swaps_needed++){
                if (max_right[num_swaps_needed] <= i){
                    res += num_swaps_needed;
                    max_right.erase(max_right.begin() + num_swaps_needed);
                    break;
                }
            }
            
            if (num_swaps_needed == n - i){
                return -1;
            }
        }
        return res;
    }
    
};
