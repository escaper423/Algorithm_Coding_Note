//problem URL: https://leetcode.com/problems/array-nesting/
class Solution {
public:
    int dfs(int num, vector<int>& nums, int cnt){
        if(visited[num] == true){
            return 0;
        }
        
        visited[num] = true;
        
        int res = dfs(nums[num],nums, cnt+1);
        return res + 1;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        visited.resize(n,false);
        
        for(int i = 0; i < n; i++){
            if (visited[nums[i]]) continue;
            
            if (nums[i] == i) {
                visited[nums[i]] = true;
                continue;
            }
            
            int tmp = dfs(nums[i], nums, 0);     
            res = max(res,tmp);
        }
        
        return res;
    }
private:
    vector<int> visited;
};
