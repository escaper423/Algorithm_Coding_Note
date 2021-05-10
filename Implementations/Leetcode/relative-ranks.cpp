//problem URL: https://leetcode.com/problems/relative-ranks/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> rank_sorted;
        
        vector<string> res(score.size(), "");
        
        for(int i = 0; i < score.size(); i++){
            rank_sorted.push_back(make_pair(score[i], i));
        }
        
        sort(rank_sorted.begin(), rank_sorted.end(), [](auto& p1, auto &p2){
            return p1.first > p2.first;
        });
        
        
        for(int i = 0; i < rank_sorted.size(); i++){
            if (i == 0){
                res[rank_sorted[i].second] = "Gold Medal";
            }
            if (i == 1){
                res[rank_sorted[i].second] = "Silver Medal";
            }
            if (i == 2){
                res[rank_sorted[i].second] = "Bronze Medal";
            }
            if (i >= 3){
                res[rank_sorted[i].second] = to_string(i+1);
            }
        }
        
        return res;
    }
};
