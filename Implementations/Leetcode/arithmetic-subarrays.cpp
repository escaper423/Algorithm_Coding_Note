//problem URL: https://leetcode.com/problems/arithmetic-subarrays/
class Solution {
public:
    bool query(vector<int> nums, int l, int r){
        vector<int> tmp(nums.begin() + l, nums.begin() + r + 1);
        sort(tmp.begin(), tmp.end());
        
        int diff = INT_MIN;
        
        for(int i = 0; i < tmp.size() - 1; i++){
            //cout << diff << " " << tmp[i+1] - tmp[i] << endl;
            if( (diff == INT_MIN) || (diff == tmp[i+1] - tmp[i])){
                diff = tmp[i+1] - tmp[i];
            }
            else return false;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        int n = nums.size();
        int m = l.size();
        for(int i = 0; i < m; i++){
            int left = l[i];
            int right = r[i];
            res.push_back(query(nums,left,right));
        }
        return res;
    }
};
