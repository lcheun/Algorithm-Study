// 골드4
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/12869

#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int dp[61][61][61]; // 체력이 a, b, c인 scv 파괴하기 위한 공격 최솟값
int scv[3];
vector<vector<int>> v = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int findMinAttack(int a, int b, int c) {
	// 전부 파괴된 경우 : 종료
	if (a == 0 && b == 0 && c == 0)
		return 0;

	// 체력이 음수가 되면 0으로 바꿔준다
	if (a < 0) return findMinAttack(0, b, c);
	if (b < 0) return findMinAttack(a, 0, c);
	if (c < 0) return findMinAttack(a, b, 0);

	int &cnt = dp[a][b][c]; // 🔥참조자 안 붙이면 실행 안 됨
	if (cnt != -1) // 이미 구한 경우
		return cnt;

	cnt = 1e9;
	for (int i=0; i<6; i++){
		cnt = min(cnt, findMinAttack(a-v[i][0], b-v[i][1], c-v[i][2]) + 1);
	}
	return cnt;
}

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> scv[i];
	}

	// 연산
	memset(dp, -1, sizeof(dp));
	int ans = findMinAttack(scv[0], scv[1], scv[2]);

	// 출력
	cout << ans;
}