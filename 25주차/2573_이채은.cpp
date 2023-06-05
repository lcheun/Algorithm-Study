#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int N, M, ans;
int map[300][300], map2[300][300];
bool visit[300][300];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = true;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visit[ny][nx] && map[ny][nx] != 0) {
                visit[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
    }
}

int count(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (map[ny][nx] == 0) cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (true) {
        memset(visit, false, sizeof(visit));
        memset(map2, 0, sizeof(map2));

        int land = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (land > 1) {
                    printf("%d", ans); return 0;
                }
                if (map[i][j] != 0 && !visit[i][j]) {
                    land++;
                    bfs(i, j);
                }
            }
        }

        if (land == 0) {
            printf("0"); return 0;
        }

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] != 0) {
                    map2[i][j] = max(0, map[i][j] - count(i, j));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = map2[i][j];
            }
        }

        ans++;
    }
}
