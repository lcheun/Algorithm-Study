#include <stdio.h>

int N, M, cnt = 0;
int map[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int backx[4] = { 1, 0, -1, 0 };
int backy[4] = { 0, -1, 0, 1 };

void search(int x, int y, int d) {
    if (map[x][y] == 0) {
        cnt++;
        map[x][y] = 2;
    }

    for (int k = d - 1; k > d - 5; k--) {

        int nk = (k + 4) % 4;
        int nx = x + dx[nk];
        int ny = y + dy[nk];

        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;

        if (map[nx][ny] == 0) {
            search(nx, ny, nk);
            return;
        }
    }

    if (map[x + backx[d]][y + backy[d]] == 1) return;
    else search(x + backx[d], y + backy[d], d);
}

int main() {
    int r, c, d;

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    search(r, c, d);

    printf("%d\n", cnt);
}
