// 골드5
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/17396

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long, long> ci;
typedef long long ll;
const ll INF = 1e10;

vector<ll> dijkstra(int start, int n, vector<vector<ci>> &graph, vector<int> &sight){
	vector<ll> dist(n, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	// 시작 정점 초기화
	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()){
		long node = pq.top().second;
		long weight = pq.top().first;
		pq.pop();

		if (dist[node] < weight){
			continue;
		}

		for (ci next : graph[node]){
			int n_node = next.first;
			int n_weight = next.second;

			if (n_node != n-1 && sight[n_node]){ // 상대 넥서스가 아니고 시야에 들어오는 경우
				continue;
			}

			if (dist[n_node] > n_weight + weight){
				dist[n_node] = n_weight + weight;
				pq.push({dist[n_node], n_node});
			}
		}
	}
	return dist;
}

int main() {
	int n, m, a, b, c;

	// 입력
	cin >> n >> m;
	vector<vector<ci>> graph(n, vector<ci>());
	vector<int> sight(n, 0);

	for (int i=0; i<n; i++){
		cin >> sight[i];
	}

	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	// 연산
	vector<ll> dist = dijkstra(0, n, graph, sight);

	// 출력
	cout << (dist[n-1] == INF ? -1 : dist[n-1]) << '\n';
}