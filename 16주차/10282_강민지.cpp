// 골드4
// Created by KangMinji on 2023-03-20.
// https://www.acmicpc.net/problem/10282

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1e8;

ci calcInfectTime(int n, int start, vector<vector<ci>> &graph){

	priority_queue<ci, vector<ci>, greater<>> q;
	vector<int> dist(n+1, MAX);

	// 시작정점 초기화
	q.push({0, start});
	dist[start] = 0;

	int cnt = 0, time = 0;

	while(!q.empty()){
		int node = q.top().second;
		int weight = q.top().first;
		q.pop();

		if (dist[node] < weight){
			continue;
		}

		cnt++; time = weight;

		for (ci next : graph[node]){
			int n_node = next.first;
			int n_weight = next.second + weight;
			if (dist[n_node] > n_weight) {
				q.push({n_weight, n_node});
				dist[n_node] = n_weight;
			}
		}
	}

	return {cnt, time};
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, d, c, a, b, s;

	// 입력
	cin >> t;
	while(t--){
		cin >> n >> d >> c;
		vector<vector<ci>> graph(n+1, vector<ci>()); // {번호, 시간}

		while(d--){
			cin >> a >> b >> s;
			graph[b].push_back({a, s});
		}

		// 연산
		auto answer = calcInfectTime(n, c, graph);

		// 출력
		cout << answer.first << ' ' << answer.second << '\n';
	}
}