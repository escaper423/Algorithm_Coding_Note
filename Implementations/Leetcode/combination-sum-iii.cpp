problem URL: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> res;
    unordered_set<vector<int>> s;
    void helper(int k,int picked, int n, int sum, vector<int> &tmp, vector<int> &numUsed){
        if (picked > k){
            return;
        }
        
        if (picked == k && sum == n && s.find(numUsed) == s.end()){
            res.push_back(tmp);
            s.insert(numUsed);
            return;
        }
        
        for(int i = 1; i <= 9; i++){
            if(numUsed[i] == false){
                numUsed[i] = true;
                tmp.push_back(i);
                helper(k, picked + 1, n, sum + i, tmp, numUsed);
                numUsed[i] = false;
                tmp.pop_back();
            }
        }
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<int> numUsed(10, false);
        helper(k,0,n,0,tmp,numUsed);
        return res;
    }
};
