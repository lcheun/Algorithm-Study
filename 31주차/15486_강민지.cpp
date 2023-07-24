// 골드5
// Created by KangMinji on 2023-07-24.
// https://www.acmicpc.net/problem/15486

#include <iostream>

using namespace std;
const int MAX = 1500001;

int dp[MAX]; // dp[i] = i-1일까지 일했을 때 받을 수 있는 돈
int money[MAX];
int time[MAX];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> money[i];
	}

	// 연산
	int answer = 0;
	for (int i = 1; i <= n + 1; i++) {
		answer = max(answer, dp[i]);
		if (i + time[i] > n + 1) continue; // 퇴사일을 넘기는 경우
		dp[i + time[i]] = max(dp[i + time[i]], answer + money[i]);
	}

	// 출력
	cout << answer << '\n';
}