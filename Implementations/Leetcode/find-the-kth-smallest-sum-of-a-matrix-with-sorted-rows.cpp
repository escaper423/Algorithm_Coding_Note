//problem URL: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
class Solution {
    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int, vector<int>>> s;
        
        pair<int, vector<int>> init;
        init.first = 0;
        
        for(int i = 0; i < mat.size(); i++){
            init.first += mat[i][0];
            init.second.push_back(0);
        }
        
        if (k == 1)
            return init.first;
        
        if (k > pow(mat[0].size() , mat.size()))
        {
            init.first = 0;
            for(int i = 0; i < mat.size(); i++){
                init.first += mat[i][mat[i].size() - 1];
            }
            return init.first;
        }
        
        k--;
        s.insert(init);
        
        while(k > 0)
        {
            auto cur_sum = s.begin()->first;
            auto cur_idxc = s.begin()->second;
            s.erase(s.begin());
            
            for(int i = 0; i < mat.size(); i++){
                if (cur_idxc[i] + 1 < mat[i].size()){
                    cur_sum += mat[i][cur_idxc[i] + 1] - mat[i][cur_idxc[i]];
                    cur_idxc[i]++;
                    s.insert({cur_sum,cur_idxc});
                    cur_idxc[i]--;
                    cur_sum += mat[i][cur_idxc[i]] - mat[i][cur_idxc[i] + 1];    
                }   
            }
            
            if(s.empty()){
                return cur_sum;
            }
            
            k--;
        }
        
        return s.begin()->first;
    }
};
