// 골드3
// Created by KangMinji on 2023-05-24.
// https://www.acmicpc.net/problem/2482

#include <iostream>
using namespace std;
const int MOD = 1000000003;
const int SIZE = 1001;

int dp[SIZE][SIZE];
int n, k;

int main() {
	// 입력
	cin >> n >> k;

	// 초기값
	for (int i=0; i<=n; i++){
		dp[i][0] = 1; // 🔥0으로 초기화하면 57% 에러
		dp[i][1] = i;
	}

	// 연산
	for (int i=2; i<=n; i++){
		for (int j=2; j<=k; j++){
			// 일반적인 경우는 dp[i][j] = dp[i-1][j] + dp[i-2][j-1];
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
		}
	}

	// 출력
	/*
	 dp[n][k]는 다름
			 	1) n번째 선택하는 경우 : n-1, 1번째 선택 x -> 2 ~ n-2
			 	=> dp[n-3][k-1]
			 	2) n번째 선택하지 않는 경우
			 	=> dp[n-1][j]
			 	=> dp[n][k] = dp[n-3][k-1] + dp[n-1][k];
	 */
	cout << (dp[n-3][k-1] + dp[n-1][k]) % MOD;
}