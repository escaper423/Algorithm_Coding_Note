//problem URL: https://leetcode.com/problems/shuffle-an-array/
class Solution {
public:
    unordered_map<int,int> m;
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        sort(arr.begin(), arr.end(), [this](int p1, int p2){
            return m[p1] < m[p2];
        });
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(arr.begin(), arr.end());
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
