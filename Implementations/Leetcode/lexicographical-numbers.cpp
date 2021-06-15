//problem URL: https://leetcode.com/problems/lexicographical-numbers/
class Solution {
private:
    vector<int> res;
public:
    void helper(int n, int cur){
        if (cur > n)
            return;
        
        res.push_back(cur);
        for(int i = 0; i <= 9; i++){
            helper(n, (cur * 10) + i);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++){
            helper(n,i);
        }
        
        return res;
    }
};
