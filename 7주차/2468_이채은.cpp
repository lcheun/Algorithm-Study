#include <stdio.h>

int N, max = 0, ans = 0;
int map[100][100];
bool visit[100][100] = { false, };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void initialize() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
}

void dfs(int x, int y, int h) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && visit[nx][ny] == false) {
			visit[nx][ny] = true;
			if (map[nx][ny] > h) dfs(nx, ny, h);
		}
	}
}

int safe(int h) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false && map[i][j] > h) {
				dfs(i, j, h);
				cnt++;
			}
		}
	}
	initialize();
	return cnt;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			max = (max > map[i][j]) ? max : map[i][j];
		}
	}

	for (int i = 0; i < max; i++) {
		int tmp = safe(i);
		if (tmp > ans) ans = tmp;
	}

	printf("%d", ans);
}
