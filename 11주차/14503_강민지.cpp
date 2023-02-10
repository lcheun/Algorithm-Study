// 골드5 / 로봇 청소기
// Created by KangMinji on 2023-02-10.
// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int board[50][50];
bool visited[50][50];

// 북, 동, 남, 서 🔥 일반 좌표와 반대!!!!
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

bool isValid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return false;
	}
	return true;
}

void dfs(int x, int y, int dir) {

	// 2. 주변 4칸 확인
	for (int i = 0; i < 4; i++) {
		int nd = (dir + 3 - i) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (!isValid(nx, ny) || board[nx][ny] == 1) {
			continue;
		}
		// 청소하지 않은 칸이 존재한다면
		if (!visited[nx][ny] && !board[nx][ny]){
			visited[nx][ny] = true;
			ans++;
			dfs(nx, ny, nd);
		}
	}

	// 2) 총소되지 않은 빈 칸이 없는 경우
	int cx = x - dx[dir];
	int cy = y - dy[dir];

	// 2-1) 후진할 수 있는 경우 - 한 칸 후진
	if (isValid(cx, cy) && board[cx][cy] == 0) {
		// 후진할 수 있을 때
		if (board[cx][cy] == 0){
			dfs(cx, cy, dir);
		}
	}
	// 2-2) 후진할 수 없다면
	else {
		cout << ans << "\n";
		exit(0);
	}
}

int main() {
	int r, c, d;

	// 입력
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	visited[r][c] = 1;
	ans = 1;

	dfs(r, c, d);
}