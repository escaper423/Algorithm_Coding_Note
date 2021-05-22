//problem URL:: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
class Solution {
private:
    vector<int> res;
public:
    void dfs(int prev, int num, int n, int k, int depth){
        if (depth == n){
            res.push_back(num);
            return;
        }
        
        for(int i = 0; i <= 9; i++){
            int ab = (depth == 1)?abs(num - i):abs(prev-i);
            //cout << "num: "<<num << " i: "<<i<< " "<<ab;
            
            if (depth == 1 && ab == k){
                //cout << " accepted"<<endl;
                dfs(i,num * 10 + i, n, k, depth + 1);
            }
            
            else if (ab == k){
                //cout << " accepted "<<endl;
                dfs(i,num * 10 + i, n, k, depth + 1);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i = 1; i <= 9; i++){
            dfs(-1,i,n,k,1);
        }
        return res;
    }
};
