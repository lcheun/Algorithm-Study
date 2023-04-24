// https://www.acmicpc.net/problem/21758
// Created by KangMinji on 2023-04-24.
// 골드5

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> honey;
	vector<int> sum;

	// 입력
	cin >> n;
	honey.assign(n + 1, 0);
	sum.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> honey[i];
		sum[i] = sum[i-1] + honey[i];
	}

	// 연산
	/*
	 * 1) 벌꿀이 왼족 끝 : 한 벌은 오른쪽 끝 & 다른 벌은 위치 미정
	 * 2) 벌꿀이 오른쪽 끝 : 한 벌은 왼쪽 끝 & 다른 벌은 위치 미정
	 * 3) 벌통이 2~N-1에 있는 경우 : 벌은 1과 N에 있는 경우
	 */
	int ans = -1;
	for (int i=2; i<n; i++){
		ans = max(ans, (sum[n]- sum[1] - honey[i]) + (sum[n] - sum[i]));
		ans = max(ans, (sum[n-1] - honey[i]) + sum[i - 1]);
		ans = max(ans, (sum[i] - sum[1]) + (sum[n-1] - sum[i-1]));
	}

	// 출력
	cout << ans << "\n";
}
