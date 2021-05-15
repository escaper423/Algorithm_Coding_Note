//problem URL: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int can_pass = n;
        int passes = 0;
        int res = 0;
        
        while(passes < can_pass && sandwiches.size() > 0) {
            if (students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                res++;
                passes = 0;
                can_pass--;
            }
            else{
                int tmp = students[0];
                students.erase(students.begin());
                students.push_back(tmp);
                passes++;
            }
        }
        
        return n - res;
            
            
    }
};
