//problem URL: https://leetcode.com/problems/string-without-aaa-or-bbb/
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";
        char last = 'c';
        
        while (a > 0 && b > 0){
            //cout << a << " " << b << endl;
            if (a > b){
                a -= 2;
                b -= 1;
                res += (last != 'a')?"aab":"baa";
            }
            else if (a < b){
                a -= 1;
                b -= 2;
                res += (last != 'b')?"bba":"abb";
            }
            else{
                b -= 1;
                a -= 1;
                res += (last == 'a')?"ba":"ab";
            }
        }
        
        while(a-- > 0)
            res += 'a';
            
        while(b-- > 0)
            res += 'b';
        
        return res;
        
    }
};
