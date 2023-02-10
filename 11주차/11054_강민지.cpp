// 골드4 / DP
// Created by KangMinji on 2023-02-10.
// https://www.acmicpc.net/problem/11054

#include <iostream>

using namespace std;

int arr[1000];
int asc_dp[1000];
int desc_dp[1000];

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 연산
	// 1) 오름차순 범위 확인
	for (int i = 0; i < n; i++) {
		asc_dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 오름차순인 경우
			if (arr[j] < arr[i]) {
				asc_dp[i] = max(asc_dp[i], asc_dp[j] + 1);
			}
		}
	}

	// 2) 내림차순 범위 확인
	for (int i = n - 1; i >= 0; i--) {
		desc_dp[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				desc_dp[i] = max(desc_dp[i], desc_dp[j] + 1);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		// asc_dp[i] = i번째 원소를 마지막 원소로 하는 증가 수열의 길이
		// desc_dp[i] = i번째 원소를 마지막 원소로 하는 감소 수열의 길이
		// i번째 원소가 겹치므로 1을 빼주어야 함
		answer = max(answer, asc_dp[i] + desc_dp[i] - 1);
	}

	// 출력
	cout << answer << "\n";
}

//int arr[1000]; int dp[1000] = {1, };
// int answer = 0;
// int max_idx = 0; // Sk의 idx
// 1) 오름차순 범위 확인
//for (int i = 0; i < n; i++) {
//	for (int j = 0; j < i; j++) {
//	// 오름차순인 경우
//		if (arr[j] < arr[i]) {
//			dp[i] = max(dp[i], dp[j] + 1);
//		}
//	}
//}

// Sk의 idx 찾기
//	for (int i=0; i<n; i++){
//		if (dp[i] >= dp[max_idx]){
//			max_idx = i;
//		}
//	}

//	for (int i = max_idx; i < n; i++) {
//		for (int j = n - 1; j > i; j--) {
//			// 내림차순인 경우
//			if (arr[i] > arr[j]) {
//				dp[j] = max(dp[i] + 1, dp[j]);
//			}
//		}
//		answer = max(answer, dp[i]);
//	}