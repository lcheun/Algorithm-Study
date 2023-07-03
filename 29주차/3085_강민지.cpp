//
// Created by KangMinji on 2023-07-03.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> board;
int dx[4] = {1, 0};
int dy[4] = {0, 1};

int countCandy(int row, int col, int dir) {
	int sum = 0, cnt = 0;
	char prev = ' ';

	for (int i=0; i<n; i++){
		if (prev == board[row][col]){
			cnt++;
		} else {
			prev = board[row][col];
			sum = max(sum, cnt);
			cnt = 1;
		}
		row += dx[dir];
		col += dy[dir];
	}
	sum = max(sum, cnt);

	return sum;
}

int findCandy() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum = max(sum, countCandy(i, 0, 1)); // 행
		sum = max(sum, countCandy(0, i, 0)); // 열
	}
	return sum;
}

int switchCandy(int x, int y, char color) {

	int sum = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < n && ny < n && board[nx][ny] != color) {
			swap(board[nx][ny], board[x][y]);
			sum = max(sum, findCandy());
			swap(board[nx][ny], board[x][y]);
		}
	}
	return sum;
}

int main() {

	// 입력
	cin >> n;
	board.assign(n, "");
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	// 연산
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, switchCandy(i, j, board[i][j]));
		}
	}

	// 출력
	cout << answer << "\n";
}
