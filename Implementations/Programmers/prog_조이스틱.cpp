#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define left -1
#define right 1

int MinimumRotate(char c){
    int res = (int)(c - 'A');
    int counter_res = (int)(26 - (c - 'A'));
    return min(res, counter_res);
}

int GetAdjacent(int start, int direction, string &name, int &dist, vector<bool> &visited){
    int dir = direction;
    int cur = start;
    
    while(name[cur] == 'A' || visited[cur] == true){
        cur = cur + dir;
        if (cur < 0){
            cur = name.length() - 1;
        }
        else if (cur >= name.length()){
            cur = 0;
        }
        dist++;
    }
    return cur;
}

/*
    알파벳을 최소로 돌리는 수 자체는 어느 경로로 가더라도 변함이 없다.
    하지만 커서가 이동하는 경우의 수 역시 여러개다.
*/

int solution(string name) {
    int answer = 0;
    
    vector<int> nodes;
    for(int i = 0; i < name.length(); i++){
        if (name[i] != 'A'){
            nodes.push_back(i);
            answer += MinimumRotate(name[i]);   
        }
    }
    vector<bool> visited(name.length(), false);
    
    int start_node = 0;
    visited[start_node] = true;
    int cnt = (name[0] != 'A');
    
    while(cnt < nodes.size()){
        int rightDist = 0, leftDist = 0;
        int leftAdjacent = GetAdjacent(start_node,left,name,leftDist,visited);
        int rightAdjacent = GetAdjacent(start_node,right,name,rightDist,visited);    
        
        int next_node, curDist;
        
        if(leftDist < rightDist){
            curDist = leftDist;
            next_node = leftAdjacent;
        }
        else{
            curDist = rightDist;
            next_node = rightAdjacent;
        }
        
        visited[next_node] = true;
        start_node = next_node;
        answer += curDist;
        cnt++;
    }
    return answer;
}
