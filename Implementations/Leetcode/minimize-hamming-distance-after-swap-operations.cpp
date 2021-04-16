struct Node{
    int parent;
    int rank;
};

//problem URL: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
class Solution {
public:
    
    vector<Node> parents;
    
    int find(int x){
        if (parents[x].parent == x){
            return x;
        }
        return find(parents[x].parent);
    }
    
    void unionFind(int x1, int x2){
        int r1 = find(x1);
        int r2 = find(x2);
        
        if (r1 != r2){
            if (parents[r1].rank > parents[r2].rank){
                parents[r2].parent = r1;
                parents[r1].rank += parents[r2].rank;
            }
            else{
                parents[r1].parent = r2;
                parents[r2].rank += parents[r1].rank;
            }
        }
    }
    
    int findMinimumHammingDistance(vector<int> &v1, vector<int> &v2){
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int p1 = 0, p2 = 0;
        int res = v1.size();
        
        while(p1 < v1.size() && p2 < v2.size()){
            if (v1[p1] == v2[p2]){
                res--;
                p1++; p2++;
            }
            else if (v1[p1] < v2[p2]){
                p1++;
            }
            else{
                p2++;
            }
            
        }
        
        return res;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        map<int,vector<int>> s;
        map<int,vector<int>> t;
        
        int len = source.size();
        parents.resize(len);
        int res = 0;
        
        sort(allowedSwaps.begin(), allowedSwaps.end());
        for(int i = 0; i < len; i++){
            parents[i].parent = i;
            parents[i].rank = 1;
        }
            
        
        for(auto &it : allowedSwaps){
            int sFirst = it[0];
            int sSecond =it[1];
            
            unionFind(sFirst, sSecond);
        }
        
        for(int i = 0; i < len; i++){
            int idx = find(i);
            s[idx].push_back(source[i]);
            t[idx].push_back(target[i]);
            
            
        }
        for(int i = 0; i < len; i++){
            int idx = find(i);
            res += findMinimumHammingDistance(s[idx], t[idx]);
            s.erase(idx);
            t.erase(idx);
        }
        
        return res;
    }
};
