#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

enum {
    START = 0,
    END = 1
};

using namespace std;

typedef struct event {
    int type;
    int time;
    event(int ty, int ti) : type(ty), time(ti) {}
} event;

int timeToSeconds(int h, int m, int s)
{
    return 3600 * h + 60 * m + s;
}

string intToString(int t) {
    string res = "";
    int h = t / 3600; res += (h < 10)?"0"+to_string(h)+":":to_string(h)+":";
    t -= h * 3600;
    int m = t / 60; res += (m < 10)?"0"+to_string(m)+":":to_string(m)+":";
    t -= m * 60;
    res += (t < 10)?"0"+to_string(t):to_string(t);
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    vector<int> st;
    string answer = "";
    vector<event> events;
    stringstream pts(play_time);
    stringstream ats(adv_time);
    int h, m, s;
    int cur = 0;
    char c;

    pts >> h >> c >> m >> c >> s;
    int p_time = timeToSeconds(h, m, s);

    ats >> h >> c >> m >> c >> s;
    int a_time = timeToSeconds(h, m, s);

    vector<int> p(p_time + 1, 0);
    st.resize(p_time + 1,0);
    
    for (const auto& log : logs) {
        int sh, sm, ssec, eh, em, esec;

        stringstream ss(log);

        ss >>
        sh >> c >> sm >> c >> ssec
        >> c >>
        eh >> c >> em >> c >> esec;
        int start_time = timeToSeconds(sh, sm, ssec);
        int end_time = timeToSeconds(eh, em, esec);
        
        events.push_back(event(START,start_time));
        events.push_back(event(END,end_time));
    }
    
    for(const auto& it: events){
        if(it.type == START){
            p[it.time]++;
        }
        else{
            p[it.time]--;
        }
    }
    for(int i = 0; i <= p_time; i++){
        if (p[i] != 0){
            cur += p[i];
        }
        p[i] = cur;
    }
    
    long long sum = 0;
    int ans_start = 0;
    
    for(int i = 0; i <= a_time; i++){
        sum += p[i];
    }
    
    long long mx = sum;
    
    for(int i = a_time+1; i <= p_time; i++){
        sum -= p[i - a_time];
        sum += p[i];
        if (sum > mx){
            ans_start = i - a_time + 1;
            mx = sum;
        }
    }
    
    answer = intToString(ans_start);
    return answer;
}

/*
   배운 점
   시간으로 된 구간을 정수로 변환하여 사용하는 법
   부분합을 이용한 구간합, Silding window를 사용하는 경우에 대해 학습하게 됨.
*/
