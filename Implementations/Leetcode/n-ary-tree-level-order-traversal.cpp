//problem URL: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        map<int, vector<int>> m;
        
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            Node* curnode = cur.first;
            int height = cur.second;
            
            m[height].push_back(curnode->val);
            for(const auto &node : curnode->children){
                q.push({node,cur.second+1});
            }
        }
        
        for(const auto &it : m){
            res.push_back(it.second);
        }
        return res;
    }
};
