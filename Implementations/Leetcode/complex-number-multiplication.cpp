//problem URL: https://leetcode.com/problems/complex-number-multiplication/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int an,ac;
        int bn,bc;
        stringstream ssa(a);
        stringstream ssb(b);
        char c;
        ssa >> an >> c >> ac;
        ssb >> bn >> c >> bc;
        string rn = to_string((an*bn) + -1*(ac*bc));
        string cn = to_string((an*bc) + (ac*bn));
        
        string res = rn + '+' + cn + 'i';
        return res;
        
    }
};
