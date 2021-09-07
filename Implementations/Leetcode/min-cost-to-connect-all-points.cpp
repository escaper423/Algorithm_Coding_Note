//problem URL: https://leetcode.com/problems/min-cost-to-connect-all-points/
class Solution {
public:
    vector<int> parents;
    
    bool Union(int n1, int n2){
        int x1 = Find(n1);
        int x2 = Find(n2);
        
        if (x1 != x2){
            parents[x2] = x1;
            return true;
        }
        return false;
    }
    
    int Find(int x){
        if (parents[x] != x){
            return Find(parents[x]);
        }
        return x;
    }
    
    typedef struct edge{
        int s;
        int d;
        int w;
        edge(int ss, int dd, int ww): s(ss), d(dd), w(ww){}
    } edge;
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int INF = 999999999;
        int n = points.size();
        vector<edge> edges;
        
        for(int i = 0; i < n; i++){
            parents.push_back(i);
        }
    
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                if (i != k){
                    edges.push_back(edge(i, k, abs(points[i][0] - points[k][0]) + abs(points[i][1] - points[k][1])));   
                }
            }
        }
        
        sort(edges.begin(), edges.end(), [](auto n1, auto n2){
            return n1.w < n2.w;
        });
        
        int connected = 0;
        int res = 0;
        for(const auto &e : edges){
            if (Union(e.s, e.d)){
                res += e.w;
                connected++;
            }
            
            if (connected == n - 1)
                break;
            
        }
        
        return res;
    }
};
