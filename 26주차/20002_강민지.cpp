// 골드5
// Created by KangMinji on 2023-06-05.
// https://www.acmicpc.net/problem/20002

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;

	// 입력
	cin >> n;
	vector<vector<int>> money(n+1, vector<int>(n+1, 0));
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> money[i][j];
		}
	}

	// 연산
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			dp[i][j] = money[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}

	// 최대값 구하기
	int answer = -1e9;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			int size = min(n-i, n-j);
			for (int k=0; k<=size; k++){
				int total = dp[i+k][j+k] - dp[i-1][j+k] - dp[i+k][j-1] + dp[i-1][j-1];
				answer = max(answer, total);
			}
		}
	}

	// 출력
	cout << answer << "\n";

}
