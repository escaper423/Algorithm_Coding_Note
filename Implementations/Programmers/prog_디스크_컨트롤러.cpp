#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define pii pair<int,int>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int t = 0, idx = 0;
    priority_queue<pii,vector<pii>, greater<pii> > q;
    sort(jobs.begin(), jobs.end());
    
    while(idx < n || !q.empty()){
        
        while(idx < n && jobs[idx][0] <= t){
            q.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        
        if (!q.empty()){
            auto cur = q.top(); q.pop();
            t += cur.first;
            answer += t - cur.second;
        }
        
        else{
            t = jobs[idx][0];   
        }
    }
    
    return answer / n;
}
