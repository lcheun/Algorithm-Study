#include <stdio.h>

int map[50][50] = { 0, };
bool visit[50][50] = { false, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void init(int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

void count(int M, int N, int x, int y) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < M && ny < N && nx >= 0 && ny >= 0 && map[nx][ny] == 1 && visit[nx][ny] == false)
            count(M, N, nx, ny);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int M, N, K, ans = 0;
        scanf("%d %d %d", &M, &N, &K);
        for (int j = 0; j < K; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] == 1 && visit[j][k] == false) {
                    ans++;
                    count(M, N, j, k);
                }
            }
        }
        printf("%d\n", ans);
        init(M, N);
    }
}
