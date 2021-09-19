//problem URL: https://leetcode.com/problems/different-ways-to-add-parentheses/
//references: https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1460358/C%2B%2B-recursion-with-Memo-0-ms-faster-than-100.00
//            https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1466456/Recursive-%2B-Memo-faster-than-100.00-of-C%2B%2B
class Solution {
public:
    unordered_map<string, vector<int>> m;
    
    int calc(int l, int r, char op){
        if (op == '+') return l+r;
        if (op == '-') return l-r;
        if (op == '*') return l*r;
        return -1;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        
        if (m.find(expression) != m.end()){
            return m[expression];
        }
        
        for(int i = 0; i < expression.length(); i++){
            if (!isdigit(expression[i])){
                auto l = diffWaysToCompute(expression.substr(0,i));
                auto r = diffWaysToCompute(expression.substr(i+1));
                
                for(int left : l){
                    for(int right : r){
                        int val = calc(left,right,expression[i]);
                        res.push_back(val);
                    }
                }
            }    
        }
        
        if (res.size() == 0){
            res.push_back(stoi(expression));
        }
        
        return m[expression] = res;
    }
};

/*
  things i didnt know
  - how to separate the expression to solve problem with dp
  
  e.g. 2+1-3 -> 2,+,(1-3) or (2+1),-,3
       2,+,(1-3) -> 2,+,-2 -> 0
       (2+1),-,3 -> 3,-,3 -> 0
*/
