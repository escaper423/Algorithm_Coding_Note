//problem URL: https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        vector<int> res;
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        
        int rank = 0;
        int last = INT_MIN;
        for(int i = 0; i < tmp.size(); i++){
            if (last < tmp[i])
                rank++;
            m[tmp[i]] = rank;
            last = tmp[i];
        }
        
        for(int i = 0; i < arr.size(); i++){
            auto elem = m.find(arr[i]);
            res.push_back(elem->second);
        }
        return res;
    }
};
