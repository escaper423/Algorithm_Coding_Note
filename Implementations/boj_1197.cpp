#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define pii pair<int,int>
#define MAX 10010

using namespace std;

typedef struct Edge{
	int cost;
	int src;
	int dst;
	Edge(int c, int s, int d) :cost(c), src(s), dst(d)
	{}

	friend bool operator<(const Edge &e1 , const Edge &e2) {
		return e1.cost < e2.cost;
	}
	friend bool operator>(const Edge& e1, const Edge& e2) {
		return e1.cost > e2.cost;
	}
}Edge;

priority_queue < Edge, vector<Edge>, greater<Edge> > pq;
int parents[MAX];

int Find(int v) {
	if (parents[v] != v)
		return Find(parents[v]);
	return v;
}

bool Union(int v1, int v2) {
	int x1 = Find(v1);
	int x2 = Find(v2);
	if (x1 == x2)
		return false;

	parents[x1] = parents[x2];
	return true;
}
int kruskal(int numVert) {
	int res = 0;
	int edge_taken = 0;

	while (!pq.empty()) {
		if (edge_taken == numVert - 1)
			break;

		auto cur = pq.top(); pq.pop();
		
		if (Union(cur.src, cur.dst)) {
			res += cur.cost;
			edge_taken++;
		}
			
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int src, dst, w;
		cin >> src >> dst >> w;
		pq.push(Edge{ w,src,dst });
	}

	for (int i = 1; i < v + 1; i++)
		parents[i] = i;

	cout << kruskal(v);
	return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
6 5 2
5 4 10
4 3 9
3 2 7
2 8 2
8 6 6
2 5 4
3 5 14
*/