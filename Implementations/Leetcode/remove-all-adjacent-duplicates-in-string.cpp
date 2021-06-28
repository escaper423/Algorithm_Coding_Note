//problem URL: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stac;
        
        for(auto &c : s){
            if (!stac.empty() && stac.top() == c){
                stac.pop();
            }
            else{
                stac.push(c);
            }
        }
        
        string res("");
        while(!stac.empty()){
            res = stac.top() + res;
            stac.pop();
        }
        return res;
    }
};
