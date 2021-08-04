problem URL: https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++){
            vector<int> tmp;
            for(int k = 0; k < n; k++){
                if (i & (1 << k)){
                    tmp.push_back(nums[k]);
                }
            }
            sort(tmp.begin(), tmp.end());
            s.insert(tmp);
        }
        
        for(const auto &it : s){
            res.push_back(it);
        }
        return res;
    }
};
