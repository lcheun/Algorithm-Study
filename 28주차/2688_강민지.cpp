// 실버1
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/2688

#include <iostream>
using namespace std;

long long dp[65][10]; // dp[n][시작하는 수]

int main() {
	int t, n;

	// 초기화
	for (int i=0; i<=9; i++)
		dp[1][i] = 1;

	for (int i=2; i<=64; i++){ // n값
		for (int j=0; j<=9; j++){ //
			for (int k=j; k<=9; k++){ // 작은값들
				dp[i][j] += dp[i-1][k];
			}
		}
	}

	cin >> t;
	while(t--){
		cin >> n;

		long long answer = 0;
		for (int i=0; i<=9; i++)
			answer += dp[n][i];

		cout << answer << '\n';
	}
}