//problem URL: https://leetcode.com/problems/largest-number
class Solution {
public:
    static bool comp(int a1, int a2){
        string s1(to_string(a1));
        string s2(to_string(a2));
        
        if((s1+s2).compare(s2+s1) > 0)
            return true;
        else
            return false;
    }
    
    string largestNumber(vector<int>& nums) {
        string res("");
        sort(nums.begin(), nums.end(), comp); 
        bool iszero = true;
        
        for(auto &it : nums){
            res += to_string(it);
            if(it > 0)
                iszero = false;
            
        }
        if (iszero)
            return "0";
        
        return res;
    }
};
