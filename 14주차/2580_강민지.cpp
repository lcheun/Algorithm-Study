// 골드4
// Created by KangMinji on 2023-01-25.
// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int board[10][10];
vector<ci> blank; // 빈 칸 채우기
bool is_fill = false;

bool check(int row, int col) {
	// 1) 행, 열 확인
	for (int i = 0; i < 10; i++) {
		if ((board[i][col] == board[row][col] && i != row)
			|| (board[row][i] == board[row][col] && i != col)) {
			return false;
		}
	}

	// 2) 3x3 확인
	int r_box = (row / 3) * 3;
	int c_box = (col / 3) * 3;
	for (int i = r_box; i < r_box + 3; i++) {
		for (int j = c_box; j < c_box + 3; j++) {
			if (board[i][j] == board[row][col] && (i != row && j != col)){
				return false;
			}
		}
	}
	return true;
}

void backtracking(int idx) {
	if (idx == blank.size()) {
		is_fill = true;
		return;
	}

	int row = blank[idx].first;
	int col = blank[idx].second;

	for (int num = 1; num < 10; num++) {
		board[row][col] = num;

		if (check(row, col)) { // 연산
			backtracking(idx + 1);
		}

		if (is_fill){
			return;
		}

		board[row][col] = 0;
	}
}

int main() {
	// 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				blank.push_back({i, j});
			}
		}
	}

	// 연산
	backtracking(0);

	// 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
}