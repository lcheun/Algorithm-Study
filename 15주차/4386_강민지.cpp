// 골드3
// Created by KangMinji on 2023-03-13.
// https://www.acmicpc.net/problem/4386

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<double, int> ci;
typedef pair<double, double> di;
const int INF = 1e5; // (n-1) * 1000;

double prim(int n, int start, vector<vector<ci>> &graph){
	double sum = 0;

	priority_queue<ci, vector<ci>, greater<>> pq;
	vector<bool> visited(n, false);
	vector<double> dist(n, INF);

	// 초기화
	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()){
		double weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]){
			continue;
		}
		visited[cur] = true;
		sum += weight;

		for (ci next : graph[cur]){
			double next_weight = next.first;
			double next_edge = next.second;

			if (!visited[next_edge] && dist[next_edge] > next_weight){
				pq.push({next_weight, next_edge});
				dist[next_edge] = next_weight;
			}
		}
	}
	return sum;
}

/*
 * 사이클 없고, 모든 간선이 연결되어야 함 => MST
 * 간선 개수 1000C2 = 500 * 999
 * 정점 개수 1000
 * => 정점 위주 prim으로
 */
int main() {
	int n;
	double x, y;

	// 입력
	cin >> n;

	vector<di> star;
	vector<vector<ci>> graph(n, vector<ci>(0));
	for (int i=0; i<n; i++){
		cin >> x >> y;
		for (int j=0; j<i; j++){ // 간선 정보 계산
			double dx = x - star[j].first;
			double dy = y - star[j].second;
			double dist = sqrt(dx*dx + dy*dy);
			graph[i].push_back({dist, j});
			graph[j].push_back({dist, i});
		}
		star.push_back({x, y});
	}

	// 연산 & 출력
	printf("%.2f", prim(n, 0, graph));
}