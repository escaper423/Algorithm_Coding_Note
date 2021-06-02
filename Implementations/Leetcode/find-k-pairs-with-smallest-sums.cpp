//problem URL: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue< 
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>
            > pq;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                pq.push({nums1[i] + nums2[j], {nums1[i],nums2[j]}});
            }
        }
        
        for(int i = 0; i < k; i++){
            auto cur = pq.top();
            res.push_back(vector<int>{cur.second.first,cur.second.second});
            pq.pop();
            
            if(pq.empty())
                break;
        }
        
        return res;
    }
};
