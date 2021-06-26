//problem URL: https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    int Find(vector<int> &p, int x){
        if (p[x] != x){
            return Find(p,p[x]);
        }
        return x;
    }
    
    bool Union(int x1, int x2, vector<int> &p){
        int r1 = Find(p,x1);
        int r2 = Find(p,x2);
        
        if(r1 != r2){
            p[r2] = r1;
            return true;
        } 
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n+1);
        for(int i = 0; i <= n; i++){
            p[i] = i;
        }
        
        int e1, e2;
        
        for(auto &edge : edges){
            if (!Union(edge[0], edge[1], p)){
                e1 = edge[0];
                e2 = edge[1];
            }
        }
        return {e1,e2};
    }
};
