//problem URL: https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1){
            return (flowerbed[0] == 0 && n <= 1 || flowerbed[0] == 1 && n == 0);    
        }
        
        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            n--;
        }
        for(int i = 1; i <flowerbed.size(); i++){
            if(i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
            
            if (i < flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            
            if (n == 0)
                return true;
        }
        
        return n <= 0;
    }
};
