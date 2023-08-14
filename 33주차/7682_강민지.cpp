// 골드5
// Created by KangMinji on 2023-08-14.
// https://www.acmicpc.net/problem/7682

#include <iostream>

using namespace std;

char board[3][3];

bool checkWin(char c) {
	// 가로 세로 3개 확인
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return true;
		if (board[0][i] == c && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return true;
	}

	// 대각선 확인
	if (board[0][0] == c && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	if (board[0][2] == c && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	return false;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	string input;
	while (cin >> input) {
		if (input == "end") {
			break;
		}
		// 보드 생성
		int x_cnt = 0;
		int o_cnt = 0;
		for (int i = 0; i < 9; i++) {
			board[i / 3][i % 3] = input[i];
			if (input[i] == 'X') x_cnt++;
			else if (input[i] == 'O') o_cnt++;

		}

		// 보드 판별
		bool isX = checkWin('X');
		bool isO = checkWin('O');

		// 1) X가 이기는 경우 : X는 3줄, X가 O보다 1개 더 많음
		// 2) O가 이기는 경우 : O는 3줄, X와 O가 같은 값
		// 3) 둘이 비기는 경우 : X가 5개, O가 4개
		if (isX && !isO && x_cnt == o_cnt + 1)
			cout << "valid\n";
		else if (!isX && isO && x_cnt == o_cnt)
			cout << "valid\n";
		else if (!isX && !isO && x_cnt == 5 && o_cnt == 4)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
}