//problem URL: https://leetcode.com/problems/basic-calculator-ii/
class Solution {
public:
    int calculate(string s) {
        stack<int> op;
        char oper = '+';
        
        int acc = 0;
        for(auto &c : s){
            if (isdigit(c)){
                acc = (acc * 10) + (c - '0');
            }
            if (!isdigit(c) && c != ' '){
                if (oper == '+'){
                    op.push(acc);
                }
                if (oper == '-'){
                    op.push(-acc);
                }
                if(oper == '*'){
                    int old = op.top(); 
                    op.pop(); 
                    op.push(old * acc);
                }
                if (oper == '/'){
                    int old = op.top();
                    op.pop();
                    op.push(old / acc);
                }
                acc = 0;
                oper = c;
            }
        }
        
        if (oper == '/'){
            acc = op.top() / acc;
            op.pop();
        }
        
        if (oper ==  '*'){
            acc = op.top() * acc;
            op.pop();
        }
            
        if (oper == '-'){
            acc = -acc;
        }
        
        while(!op.empty()){
            acc = op.top() + acc; op.pop();
        }
        
        return acc;
    }
};
