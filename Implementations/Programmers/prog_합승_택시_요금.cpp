#include <string>
#include <vector>
#define INF 9000000
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for(const auto& fare: fares){
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    
    for(int i = 1; i <= n; i++){
        for(int k = 1; k<= n; k++){
            for(int j = 1; j <=n; j++){
                if (dist[k][j] > dist[k][i] + dist[i][j] &&
                    dist[k][i] != INF &&
                   dist[i][j] != INF
                   )
                {
                    dist[k][j] = dist[k][i] + dist[i][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if (i != s){
            answer = min(answer, min(dist[s][i] + dist[i][a] + dist[i][b], dist[s][a] + dist[s][b]));    
        }
    }
    return answer;
}
/*
  
  - INF의 값이 문제가 됬었음. (구간들의 합이 때로 INF의 값을 넘어가 버리는 것이 문제인 것으로 추정됨.)
  - Floyd-warshall 알고리즘을 이용하면 모든 정점간의 최소 거리를 구할 수 있음. (dijkstra 알고리즘 사용해도 가능)
   
*/
