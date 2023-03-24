// 골드5
// Created by KangMinji on 2023-03-20.
// https://www.acmicpc.net/problem/2096

#include <iostream>
#include <vector>
using namespace std;

/*
 * 1) 바로 아래의 수로 넘어가거나
 * 2) 바로 아래의 수와 붙어있는 수로만 이동
 */
int main() {
	int n, a, b, c;

	int max_dp[3] = {0, 0, 0};
	int min_dp[3] = {10, 10, 10};
	int dp[3] = {0, 0, 0};
	// 입력
	cin >> n;
	cin >> max_dp[0] >> max_dp[1] >> max_dp[2];

	for (int i=0; i<3; i++){
		min_dp[i] = max_dp[i];
	}

	for(int i=1; i<n; i++){
		cin >> dp[0] >> dp[1] >> dp[2];

		int tmp0 = max_dp[0], tmp1 = max_dp[1], tmp2 = max_dp[2];

		// 최대 dp
		max_dp[0] = max(tmp0, tmp1) + dp[0];
		max_dp[1] = max(max(tmp0, tmp1), tmp2) + dp[1];
		max_dp[2] = max(tmp1, tmp2) + dp[2];

		// 최소 dp
		tmp0 = min_dp[0], tmp1 = min_dp[1], tmp2 = min_dp[2];
		min_dp[0] = min(tmp0, tmp1) + dp[0];
		min_dp[1] = min(min(tmp0, tmp1), tmp2) + dp[1];
		min_dp[2] = min(tmp1, tmp2) + dp[2];
	}

	// 출력
	int max_score = max(max(max_dp[0], max_dp[1]), max_dp[2]);
	int min_score = min(min(min_dp[0], min_dp[1]), min_dp[2]);
	cout << max_score << ' ' << min_score;
}