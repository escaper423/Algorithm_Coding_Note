//problem URL: https://leetcode.com/problems/online-election/
class TopVotedCandidate {
public:
    int freq[5001] = {0};
    vector<int> leadings;
    vector<int> time;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times):
        time(times)
    {
        int mVal = 0;
        int mIdx = -1;
        for(int i = 0; i < persons.size(); i++){
            
            freq[persons[i]]++;
            
            if (freq[persons[i]] >= mVal){
                leadings.push_back(persons[i]);
                mVal = freq[persons[i]];
                mIdx = persons[i];
            }
            else{
                leadings.push_back(mIdx);
            }
        }
          
    }
    
    int q(int t) {
        int pos = upper_bound(time.begin(), time.end(), t) - time.begin();
        return leadings[pos-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
