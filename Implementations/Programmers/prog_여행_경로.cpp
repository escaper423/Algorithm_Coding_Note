#include <string>
#include <vector>

using namespace std;
vector<int> visited;
string tmp;

void dfs(vector<vector<string>> &tickets, int depth, string route, string cur){
    int n = tickets.size();
    if (depth == n){
        if (tmp == "" || tmp.compare(route) > 0){
            tmp = route;
        }
        return;
    }
    
    for(int i = 0; i < n; i++){
        if (tickets[i][0] == cur && visited[i] == false){
            visited[i] = true;
            dfs(tickets,depth+1,route + tickets[i][1], tickets[i][1]);
            visited[i] = false;
        }
    }
        
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    
    visited.resize(n, 0);
    
    for(int i = 0; i < n; i++){
        dfs(tickets,0,"ICN","ICN");
    }
    
    for(int i = 0; i < tmp.length(); i+=3){
        answer.push_back(tmp.substr(i,3));
    }
    return answer;
}
