//problem URL: https://leetcode.com/problems/rabbits-in-forest/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int,int> s;
        for(int i = 0; i < answers.size(); i++){
            if (s.find(answers[i]) != s.end()){
                s[answers[i]]++;
                
                if(s[answers[i]] == answers[i] + 2){
                    s[answers[i]] = 1;
                    res += answers[i] + 1;
                }
                continue;
            }
            
            else{
                res += answers[i] + 1;
            }
            s[answers[i]]++;
        }
        return res;
    }
};
