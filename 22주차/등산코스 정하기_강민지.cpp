//
// Created by KangMinji on 2023-04-28.
// https://school.programmers.co.kr/learn/courses/30/lessons/118669

#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

const int MAX = 1e7 + 1;
const int SIZE = 50001;

vector<int> intensity(SIZE, MAX);
vector<vector<ci>> graph(SIZE);
vector<bool> is_summit(SIZE, false);

vector<int> calcMinIntensity(priority_queue<ci, vector<ci>, greater<>> &pq){
	int ans_intensity = MAX;
	int summit = MAX;

	while(!pq.empty()){
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// 더 빠른 통로가 있다면 pass
		if (ans_intensity < weight){
			continue;
		}

		// 봉우리면 queue에 다시 안 넣음
		if (is_summit[node]){
			ans_intensity = min(ans_intensity, weight);
			summit = min(summit, node);
			continue;
		}

		for (ci next : graph[node]){
			if (intensity[next.first] > max(weight, next.second)){
				intensity[next.first] = max(weight, next.second);
				pq.push({intensity[next.first], next.first});
			}
		}
	}
	return {summit, ans_intensity};
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;

	// 초기 생성
	for (int summit : summits){
		is_summit[summit] = true;
	}
	for (vector<int> path : paths){
		int u = path[0];
		int v = path[1];
		int w = path[2];
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	// 연산
	priority_queue<ci, vector<ci>, greater<>> pq; // {intensity, gate}
	for (int gate : gates){
		pq.push({0, gate});
		intensity[gate] = -1; // 다른 출입구로 이동 방지
	}
	answer = calcMinIntensity(pq);

	return answer;
}