// ❌ 메모리 초과 실버1
// Created by KangMinji on 2023-03-20.
// https://www.acmicpc.net/problem/16174

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[2] = {0, 1}; // {오른쪽, 아래}
int dy[2] = {1, 0};

bool playGame(int n, vector<vector<int>> &board) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;

	// 시작 정점 초기화
	q.push({0, 0});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;

		int move = board[x][y];
		for (int i = 0; i < 2; i++) {
			int nx = x + move * dx[i];
			int ny = y + move * dy[i];

			// 보드 범위 내에 있지 않은 경우
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (!visited[nx][ny]) {
				if (board[nx][ny] == -1) {
					return true;
				}
				q.push({nx, ny});
			}
		}
	}
	return false;
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	if (playGame(n, board)) {
		cout << "HaruHaru\n";
	} else {
		cout << "Hing\n";
	}
}