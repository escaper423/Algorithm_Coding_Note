#include <string>
#include <vector>
#include <queue>

using namespace std;

int countDiff(string &a1, string &a2){
    int p1 = 0, p2 = 0;
    int cnt = 0;
    while(p1 < a1.length()){
        if (a1[p1++] != a2[p2++])
            cnt++;
    }
    return cnt;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    q.push({begin,0});

    while(!q.empty()){
        pair<string,int> cur = q.front(); 
        q.pop();

        if (cur.first.compare(target) == 0){
            answer = cur.second;
            break;
        }

        else if (cur.second > words.size()){
            break;
        }

        for(auto &it : words){
            if (countDiff(cur.first, it) == 1){
                q.push({it,cur.second+1});
            }
        }
    }
    return answer;
}
