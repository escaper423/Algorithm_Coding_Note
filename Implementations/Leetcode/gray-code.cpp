//problem URL: https://leetcode.com/problems/gray-code/
class Solution {    
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int sqn = pow(2,n);
        for(int i = 0; i < sqn; i++){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
