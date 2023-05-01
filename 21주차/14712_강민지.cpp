// https://www.acmicpc.net/problem/14712
// Created by KangMinji on 2023-04-24.
// 골드5

#include <iostream>
using namespace std;

int n, m;
bool board[27][27];
int answer = 0;

// (+1, 0) (0, +1) (+1 +1)로 하면 안 됨.... -> https://velog.io/@lsh9672/%EB%B0%B1%EC%A4%80-%EB%84%B4%EB%AA%A8%EB%84%B4%EB%AA%A814712%EB%B2%88
// 그리고 왜 -1 -1 검사하는데 인덱스 에러가 안 나지??
bool canPlace(int x, int y) {
	return !(board[x - 1][y] && board[x][y - 1] && board[x - 1][y - 1]);
}

void backtracking(int cnt) {
	if (cnt == n * m) {
		answer++;
		return;
	}

	int x = cnt / m;
	int y = cnt % m;

	if (canPlace(x, y)) { // 놓는 경우
		board[x][y] = true;
		backtracking(cnt + 1);
	}
	// 안 놓는 경우
	board[x][y] = false;
	backtracking(cnt + 1);
}

int main() {

	// 입력
	cin >> n >> m;

	// 연산
	backtracking(0);

	// 출력
	cout << answer << '\n';
}