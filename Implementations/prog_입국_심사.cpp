#include <string>
#include <vector>

using namespace std;

long long getEndTimes(long long m, vector<int> times){
    long long cnt = 0;
    for(int i = 0; i < times.size(); i++){
        cnt += m/(long long)times[i];
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l = 0, r = 1e14;
    while(l <= r){
        long long m = l + (r-l)/2;
        long long res = getEndTimes(m,times);
        if (res >= n){
            answer = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return answer;
}
