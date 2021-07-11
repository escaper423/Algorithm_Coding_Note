//problem URL: https://leetcode.com/problems/monotone-increasing-digits/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int res = 0;
        int num = n;
        vector<int> v;
        while(n > 0){
            v.push_back(n%10);
            n/=10;
        }
        
        reverse(v.begin(), v.end());
        
        int pos_to_collapse = 0;
        bool hasDownward = false;
        
        for(int i = 1; i < v.size(); i++){
            if(v[i] > v[i-1] && !hasDownward){
                pos_to_collapse = i;
            }
            else if (v[i] < v[i-1]){
                hasDownward = true;
                break;
            }
        }
        
        if (!hasDownward)
            return num;
        
        int idx = v.size() - 1;
        for(;idx > pos_to_collapse; idx--){
            v[idx] = 9;
        }
        v[idx]--;
        
        for(int i = 0; i < v.size(); i++){
            res = (res * 10) + v[i];
        }
        return res;
    }
};
