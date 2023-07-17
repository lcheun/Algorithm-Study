// 골드1
// Created by KangMinji on 2023-07-16.
// https://www.acmicpc.net/problem/9328

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 102;
typedef pair<int, int> ci;

int h, w;
string keystr;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool key[26];
char board[MAX][MAX];
bool visited[MAX][MAX];

int bfs() {
	queue<ci> q;
	queue<ci> door[26]; // 열쇠가 없어서 못 연 문들 저장

	q.push({0, 0});
	visited[0][0] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue; // 1~h까지 가지는데 건물 밖도 가능
			if (visited[nx][ny] || board[nx][ny] == '*') continue;
			visited[nx][ny] = true;
			// 1) 열쇠인 경우
			if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
				int k = board[nx][ny] - 'a';
				key[k] = true;
				// 못 연 문 있는 경우 다 열어주기
				while (!door[k].empty()) {
					q.push(door[k].front());
					door[k].pop();
				}
			}
				// 2) 문인 경우
			else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
				int k = board[nx][ny] - 'a' + 32;
				if (!key[k]) { // 못 여는 문인 경우
					door[k].push({nx, ny});
					continue;
				}
			}
				// 3) 문서인 경우
			else if (board[nx][ny] == '$') {
				cnt++;
			}
			q.push({nx, ny});
		}
	}
	return cnt;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w;

		// 초기화
		fill(key, key + 26, false);
		for (int i = 0; i <= h + 1; i++) {
			fill(board[i], board[i] + w + 2, ' '); // board도 초기화 필요
			fill(visited[i], visited[i] + w + 2, false);
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> board[i][j];
			}
		}

		cin >> keystr;
		if (keystr != "0") {
			for (char c: keystr) {
				key[c - 'a'] = true;
			}
		}

		// 연산 & 출력
		cout << bfs() << '\n';
	}
}