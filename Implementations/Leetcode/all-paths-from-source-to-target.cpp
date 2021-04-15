//problemURL: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &graph, int node, vector<int> g){
        g.push_back(node);
        if (node == graph.size() - 1)
            res.push_back(g);
        
        for(auto & it : graph[node]){
            dfs(graph,it,g);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, vector<int>());
        return res;
    }
};
