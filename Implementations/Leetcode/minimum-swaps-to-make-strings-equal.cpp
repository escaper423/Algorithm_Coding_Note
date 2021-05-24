//problem URL: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int res = 0;
        stack<char> stac1;
        stack<char> stac2;
        
        for(int i = 0; i < s1.length(); i++){
            if (s1[i] != s2[i]){
                char old1 = (!stac1.empty())?stac1.top():'1';
                char old2 = (!stac2.empty())?stac2.top():'2';
                
                //yy
                //xx
                if (s1[i] == old1 && s2[i] == old2){
                   res++;
                    stac1.pop(); stac2.pop();
                }
                else{
                    stac1.push(s1[i]);
                    stac2.push(s2[i]);
                }
            }
        }
        
        if (stac1.size() % 2 == 0){
            
            res += (stac1.size() / 4) * 2 + (stac1.size() % 4) ;
            return res;
        }
        else return -1;
    }
};
