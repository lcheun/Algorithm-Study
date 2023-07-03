// 골드2
// Created by KangMinji on 2023-07-03.
// https://www.acmicpc.net/problem/1949

#include <iostream>
#include <vector>
using namespace std;

int dp[10001][2]; // 0 (안 우수), 1 (우수)
int people[10001];
bool visited[10001];
vector<int> tree[10001];

void dfs(int cur) {
	visited[cur] = true;

	dp[cur][0] = 0;
	dp[cur][1] = people[cur];

	for (int i=0; i<tree[cur].size(); i++){
		int next = tree[cur][i];
		if (visited[next]) continue;
		dfs(next);

		// 안 우수 마을 : 다음 마을이 안 우수한 경우, 우수한 경우 중 최댓값 선택
		dp[cur][0] += max(dp[next][0], dp[next][1]);
		// 우수 마을 : 다음 마을이 안 우수한 경우에만 선택 가능
		dp[cur][1] += dp[next][0];
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, u, v;

	// 입력
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> people[i];

	for (int i=1; i<n; i++){
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	// 연산
	dfs(1);

	// 출력
	cout << max(dp[1][0], dp[1][1]);
}