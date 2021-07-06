//problem URL: https://leetcode.com/problems/reduce-array-size-to-the-half/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        
        for(auto & it : m){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end(), [](auto &p1, auto &p2){return p1 > p2;});
        
        
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            if (sum >= arr.size() / 2){
                return i+1;
            }
        }
        return -1;
    }
};
