//problem URL: https://leetcode.com/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        int carry = 0;
        
        while(p1 >= 0 && p2 >= 0){
            int to_add = (int)(num1[p1] - '0') + (int)(num2[p2] -'0') + carry;
            if(to_add >= 10){
                carry = 1;
                to_add %= 10;
            }
            else{
                carry = 0;
            }
            res = (char)(to_add + '0')+ res;
            p1--; p2--;
        }
        
        while(p1 >= 0){
            int to_add = (int)(num1[p1] -'0') + carry;
            if(to_add >= 10){
                carry = 1;
                to_add %= 10;
            }
            else{
                carry = 0;
            }
            res = (char)(to_add + '0')+res;
            p1--;
        }
        
        while(p2 >= 0){
            int to_add = (int)(num2[p2] -'0') + carry;
            if(to_add >= 10){
                carry = 1;
                to_add %= 10;
            }
            else{
                carry = 0;
            }
            res = (char)(to_add + '0')+res;
            p2--;
        }
        
        if(carry == 1){
            res = (char)(1 + '0')+res;
        }
        
        return res;
    }
};
