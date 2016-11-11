#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#define infinite 987654321
using namespace std;

struct Node{
	int index;
	long long int dist;
	bool operator<(const Node& b) const{
		return dist > b.dist;
	}
};
vector<Node> graph[20003];
priority_queue<Node> pq;
Node dist[200003];
int main() {
	int v,e; scanf("%d%d", &v, &e);
	int start; scanf("%d", &start);

	for (int i = 1; i <= e; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		Node input = { v,w };
		graph[u].push_back(input);
	}
	for (int i = 1; i <= v; i++) {
		dist[i].index = i;
		if (i == start)dist[start].dist = 0;
		else dist[i].dist = infinite;
		pq.push(dist[i]);
	}
	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();
		for (int i = 0; i < graph[now.index].size(); i++) {
			if (dist[graph[now.index][i].index].dist > graph[now.index][i].dist + dist[now.index].dist){
				dist[graph[now.index][i].index].dist = graph[now.index][i].dist + dist[now.index].dist;
			    pq.push(dist[graph[now.index][i].index]);
            }
		}
	}
		
	for (int i = 1; i <= v; i++) {
		if (dist[i].dist == infinite) printf("INF\n");
		else printf("%lld\n", dist[i].dist);
	}
}
