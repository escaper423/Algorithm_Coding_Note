//problem URL: https://leetcode.com/problems/find-k-closest-elements/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (idx == arr.size() || (idx > 0 && abs(arr[idx]-x) >= abs(arr[idx-1] - x))){
            idx = idx-1;
        }
        
        int l = idx-1;
        int r = idx+1;
        res.push_back(arr[idx]); 
        k--;
        
        while(k > 0){
            int right = -1;
            int left = -1;
            
            if (r < arr.size()){
                right = abs(arr[r] - x);
            }
            
            if (l >= 0){
                left = abs(arr[l] - x);
            }
            
            if(left == -1 || (r < arr.size() && right < left)){
                res.push_back(arr[r]);
                r++; k--;
            }
            else if (right == -1 || (l >= 0 && right >= left)){
                res.push_back(arr[l]);
                l--; k--;
            }
            else break;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
