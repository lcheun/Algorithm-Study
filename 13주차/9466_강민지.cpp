// 골드3
// Created by KangMinji on 2023-02-23.
// https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000;

vector<int> graph;
vector<bool> visited;
vector<bool> done;
int answer = 0;

void checkCycle(int cur) {
	visited[cur] = true;
	int next = graph[cur];

	// 대상 학생이 아직 방문되지 않은 경우 -> 방문 체크
	if (!visited[next]) {
		checkCycle(next);
	}

	// 대상 학생이 방문은 됐지만 아직 팀 결성 못한 경우(사이클 탐색 끝)
	// -> 사이클 내부 노드를 전부 count
	else if (!done[next]) {
		answer++; // 사이클 시작 학생
		for (int i = next; i != cur; i = graph[i]) {
			answer++; // 사이클 내부에 있는 학생
		}
	}
	done[cur] = true;
}

// 사이클 찾는 문제
int main() {
	int t, n;

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;

		graph.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}

		// 연산
		visited.assign(n + 1, false);
		done.assign(n + 1, false);
		answer = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				checkCycle(i);
			}
		}

		// 출력
		cout << n - answer << "\n";
	}
}