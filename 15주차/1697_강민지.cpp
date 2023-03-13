// 실버1 / BFS
// Created by KangMinji on 2023-03-13.
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int ans = 0;
bool visited[100001];

bool check(int x){
	return x >= 0 && x <= 100000;
}

void bfs(int start, int end){
	queue<ci> q;
	q.push({start, 0});
	visited[start] = true;

	while(!q.empty()){
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == end){
			cout << cost;
			exit(0);
		}

		int w1 = cur - 1;
		int w2 = cur + 1;
		int w3 = cur * 2;

		if (check(w1) && !visited[w1]){
			q.push({w1, cost+1});
			visited[w1] = true;
		}
		if (check(w2) && !visited[w2]){
			q.push({w2, cost+1});
			visited[w2] = true;
		}
		if (check(w3) && !visited[w3]){
			q.push({w3, cost+1});
			visited[w3] = true;
		}

	}
}

int main() {
	int n, k;

	// 입력
	cin >> n >> k;

	// 연산
	bfs(n, k);

	// 출력
	cout << ans << "\n";
}