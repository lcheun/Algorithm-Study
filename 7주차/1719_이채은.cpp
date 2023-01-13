#include <stdio.h>

int N, M;
int dist[201][201], path[201][201];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = 1000000000;
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        dist[x][y] = dist[y][x] = z;
        path[x][y] = y;
        path[y][x] = x;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    if (j != i) path[j][k] = path[j][i];
                }
            }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (path[i][j]) printf("%d ", path[i][j]);
            else printf("%c ", '-');
        }
        printf("\n");
    }
}
