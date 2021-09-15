//problem URL: https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        int seq = 1;
        for(int i = 0; i < arr.size() - 1; i++){
            if ((i % 2 == 0 && arr[i] > arr[i+1]) || (i % 2 != 0 && arr[i] < arr[i+1])){
                res = max(res, ++seq);
            }
            else{
                seq = 1;
            }
        }
        
        seq = 1;
        
        for(int i = 0; i < arr.size() - 1; i++){
            if ((i % 2 != 0 && arr[i] > arr[i+1]) || (i % 2 == 0 && arr[i] < arr[i+1])){
                res = max(res, ++seq);
            }
            else{
                seq = 1;
            }
        }
        return res;
    }
};
