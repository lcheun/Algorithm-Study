// 실버1
// Created by KangMinji on 2023-08-14.
// https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 10005;

int n, d;
int s, e, w;
int dp[10005];
vector<ci> graph[MAX];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> d;
	for (int i=0; i<n; i++){
		cin >> s >> e >> w;
		if (e > d) continue; // 역주행 불가능하므로
		graph[e].push_back({s, w});
	}

	// 연산
	dp[0] = 0;
	for (int i=1; i<=d; i++){
		dp[i] = dp[i-1] + 1; // 지름길 없는 경우
		for (int j=0; j<(int)graph[i].size(); j++) { // 지름길이 있는 경우
			dp[i] = min(dp[i], dp[graph[i][j].first] + graph[i][j].second);
		}
	}

	// 출력
	cout << dp[d];
}