//problem URL: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int dijkstra(int n, int start, vector<vector<pair<int,int>>> &g, int mx_dist){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(n, 100000);
        dist[start] = 0;
        q.push({0,start});
        
        while(!q.empty()){
            int cur = q.top().second;
            int cost = q.top().first;
            q.pop();
            
            for(auto &it: g[cur]){
                if (dist[it.first] > dist[cur] + it.second){
                    dist[it.first] = dist[cur] + it.second;
                    q.push({dist[cur] + cost, it.first});
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if (i != start && dist[i] <= mx_dist)
                cnt++;
        }
        return cnt;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>());
        
        int cur_min_neighbors = INT_MAX;
        int res = -1;
        
        for(auto &it : edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        
        for(int i = 0; i < n; i++){
            int cnt = dijkstra(n,i, g, distanceThreshold);
            if (cnt <= cur_min_neighbors){
                res = i;
                cur_min_neighbors = cnt;
            }
        }
        
        return res;
        
    }
};
