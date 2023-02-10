// 골드4 / bfs
// Created by KangMinji on 2023-02-10.
// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int board[8][8];
int temp[8][8];
vector<ci> virus;
int n, m;
int ans = -1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool checkValid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || temp[x][y] != 0) {
		return false;
	}
	return true;
}

void copyBoard(){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			temp[i][j] = board[i][j];
		}
	}
}

int bfs() {
	// 바이러스 퍼지는 경우, 별도의 map 필요
	copyBoard();

	queue<ci> q;

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (!checkValid(nx, ny)) {
					continue;
				}

				q.push({nx, ny});
				temp[nx][ny] = 2;
			}
		}
	}

	// 안전영역 구하기
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!temp[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

void wall(int cnt) {
	if (cnt == 3) {
		ans = max(ans, bfs());
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) { // 빈 칸이 아닌 경우
				continue;
			}
			board[i][j] = 1;
			wall(cnt + 1);
			board[i][j] = 0;
		}
	}
}

int main() {

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			// bfs용 바이러스 저장
			if (board[i][j] == 2) {
				virus.push_back({i, j});
			}
		}
	}
	// 연산
	wall(0);

	// 출력
	cout << ans << "\n";
}