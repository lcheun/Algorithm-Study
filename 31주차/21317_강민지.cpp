// 실버1
// Created by KangMinji on 2023-07-24.
// https://www.acmicpc.net/problem/21317

#include <iostream>

using namespace std;

int dp[22][2]; // dp[x][1] = x까지 오는데 매우 큰 점프를 사용한 경우
int energy[22][2];

int main() {
	int n, k;

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> energy[i][0] >> energy[i][1];
	}
	cin >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 5005;
		dp[i][1] = 5005;
	}

	// 연산
	dp[1][0] = dp[1][1] = 0;
	dp[2][0] = energy[1][0];
	dp[3][0] = min(energy[1][0] + energy[2][0], energy[1][1]);

	for (int i=4; i<=n; i++){
		dp[i][0] = min(dp[i-1][0] + energy[i-1][0], dp[i-2][0] + energy[i-2][1]);
		dp[i][1] = min(min(dp[i-1][1] + energy[i-1][0], dp[i-2][1] + energy[i-2][1]), dp[i-3][0] + k);
	}

	// 출력
	cout << min(dp[n][0], dp[n][1]) << '\n';
}