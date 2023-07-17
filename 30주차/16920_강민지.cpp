// 골드2
// Created by KangMinji on 2023-07-13.
// https://www.acmicpc.net/problem/16920

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
const int MAX = 1001;
typedef tuple<int, int, int> tp;

int n, m, p;
string board[MAX];
int step[10];
int area[10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<tp> qlist[10];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
		cin >> step[i];

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			// 플레이어가 차지한 경우
			if (board[i][j] != '.' && board[i][j] != '#') {
				int people = board[i][j] - '0';
				area[people] += 1;
				qlist[people].push({i, j, step[people]});
			}
		}
	}

	// 연산
	while (true) {
		bool can_expand = false;

		for (int i = 1; i <= p; i++) {
			queue<tp> nextq;

			// 문제 잘못 읽음
			// 현재 성에서 1~step[i] 거리에 있는 성들을 다 자기 영토로 만드는 것!
			queue<tp> q = qlist[i];
			while (!q.empty()) {
				int x, y, cnt;
				tie(x, y, cnt) = q.front();
				q.pop();

				if (cnt == 0) {
					nextq.push({x, y, step[i]});
					continue;
				}

				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] != '.') continue;
					board[nx][ny] = (char) (i + 48);
					area[i]++;
					q.push({nx, ny, cnt - 1});
					can_expand = true;
				}
			}
			qlist[i] = nextq;
		}

		if (!can_expand) {
			break;
		}
	}

	// 출력
	for (int i = 1; i <= p; i++) {
		cout << area[i] << ' ';
	}
}