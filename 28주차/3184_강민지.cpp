// 실버1
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/3184

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int sheep_cnt = 0, wolf_cnt = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char board[251][251];
int visited[251][251];

void bfs(int a, int b) {
	queue<ci> q;

	q.push({a, b});
	visited[a][b] = true;

	int sheep = 0, wolf = 0;
	if (board[a][b] == 'o') sheep++;
	if (board[a][b] == 'v') wolf++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '#' || visited[nx][ny]) continue;
			if (board[nx][ny] == 'o') sheep++;
			if (board[nx][ny] == 'v') wolf++;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}

	if (sheep > wolf) sheep_cnt += sheep;
	else wolf_cnt += wolf;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '#' && !visited[i][j])
				bfs(i, j);
		}
	}

	cout << sheep_cnt << ' ' << wolf_cnt << '\n';
}