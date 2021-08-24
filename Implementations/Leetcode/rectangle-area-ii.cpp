//problem URL: https://leetcode.com/problems/rectangle-area-ii/
enum{
    END = -1,
    START = 0,
    
};

typedef struct event{
    int x;
    int y1;
    int y2;
    int type;
    
    event(int x, int yb, int yt, int t):
    x(x), y1(yb), y2(yt), type(t){}
} event;

class Solution {
    
public:
    long long addArea(int width, multiset<pair<int,int>> &intervals){
        long long area = 0;
        int btm = 0;
        
        //it.first : bottom of current y interval
        //it.second : top of current y interval
        
        for(const auto &it : intervals){
            btm = max(btm, it.first);
            
            if(it.second > btm){
                area += (long long)((long long)width * (long long)(it.second - btm));
                btm = it.second;    
            }
        }
        
        return area;
    }
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long res = 0;
        int MOD = 1e9+7;
        vector<event> e;
        for(const auto &it : rectangles) {
            e.push_back(event(it[0], it[1], it[3], START));
            e.push_back(event(it[2], it[1], it[3], END));
        }
        
        
        sort(e.begin(), e.end(), [](event e1, event e2){
            if (e1.x < e2.x)
                return true;
            if (e1.x > e2.x)
                return false;
            
            return e1.type > e2.type;
        });
        
        int pre_x = 0;
        
        multiset<pair<int,int>> intervals;
        
        for(auto &it : e){
            int cur_x = it.x;
            res += addArea(cur_x - pre_x,intervals);
            
            if (it.type == START){
                intervals.insert(make_pair(it.y1,it.y2));
            }
            else{
                auto elem = find(intervals.begin(), intervals.end(), make_pair(it.y1,it.y2));
                if(elem != intervals.end()){
                    intervals.erase(elem);    
                }
            }
            
            pre_x = cur_x;
        }
        
        return (int)(res%MOD);
    }
};
