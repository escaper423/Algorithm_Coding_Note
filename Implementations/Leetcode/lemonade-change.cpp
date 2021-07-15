//problem URL: https://leetcode.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[2] = {0,0};
        
        for(const auto& b: bills){
            if (b == 5){
                change[0]++;
            }
            
            if (b == 10){
                change[0]--;
                if (change[0] < 0)
                    return false;
                change[1]++;
            }
            
            if (b == 20){
                if(change[1] > 0 && change[0] > 0){
                    change[1]--; change[0]--;
                }
                else if (change[0] >= 3){
                    change[0] -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;    
    }
};
