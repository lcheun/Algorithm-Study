//
// Created by KangMinji on 2023-01-27.
//

#include <iostream>
using namespace std;

// dp[n][k] = p : k개 더해서 합이 n이 되는 경우는 p가지
int dp[201][201]; // N이 되기 위해 K가지 방법이 있음

int main() {
	int N, K;

	// 입력
	cin >> N >> K;

	// 연산
	// k=1인 경우는 p=1
	for (int i=0; i<=N; i++){
		dp[i][1] = 1;
	}

	// n=1인 경우는 p=n
	for (int i=0; i<=K; i++){
		dp[1][i] = i;
	}

	// 나머지 경우 계산
	// dp[n][k] = dp[n-1][k-1]
	for (int i=2; i<=N; i++){
		for (int j=2; j<=K; j++){
			dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % 1000000000;
		}
	}

	cout << dp[N][K] << "\n";
}