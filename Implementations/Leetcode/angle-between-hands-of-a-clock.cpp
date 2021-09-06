problem URL: https://leetcode.com/problems/angle-between-hands-of-a-clock/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_hr = (360.0 * ((double)hour/12.0));
        double angle_mn = (360/60) * minutes;
        
        if(angle_hr == 360.0)
            angle_hr = 0;
        
        angle_hr += ((360.0/60.0)*5.0) * (double)((double)minutes/60.0);
        
        return min(abs(angle_hr - angle_mn), min(abs((angle_mn + 360.0) - angle_hr), abs((angle_hr + 360) - angle_mn)));
        
    }
};
