// 골드3
// Created by KangMinji on 2023-04-28.
// https://www.acmicpc.net/problem/2616

#include <iostream>
#include <vector>
using namespace std;

int dp[4][50001]; // dp[4][n+1]로 하면.....안 됨

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, people, cnt;
	vector<int> sum;

	// 입력
	cin >> n;
	sum.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> people;
		sum[i] = sum[i - 1] + people;
	}
	cin >> cnt;

	// 연산 : https://comyoung.tistory.com/184
	for (int i = 1; i <= 3; i++) {
		for (int j = i * cnt; j <= n; j++) {
			// dp[i][j-1] : j번쨰 객차를 선택하지 않은 경우의 사람 수
			// dp[i-1][j-cnt] + sum[j] - sum[j-cnt] : j번째 객차 선택한 경우
			dp[i][j] = max(dp[i][j - 1],
						   dp[i - 1][j - cnt] + (sum[j] - sum[j - cnt]));
		}
	}

	// 출력
	cout << dp[3][n];
}