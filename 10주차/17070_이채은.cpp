#include <stdio.h>

int N, ans = 0;
int house[17][17];
int dx[] = { 1, 0, 1 };
int dy[] = { 0, 1, 1 };

void dfs(int x, int y, int d) {
    if (x == N && y == N) {
        ans++; return;
    }
    if (d == 0) {
        if (y + 1 <= N && house[x][y + 1] == 0)
            dfs(x, y + 1, 0);
    }
    else if (d == 1) {
        if (x + 1 <= N && house[x + 1][y] == 0)
            dfs(x + 1, y, 1);
    }
    else {
        if (y + 1 <= N && house[x][y + 1] == 0)
            dfs(x, y + 1, 0);
        if (x + 1 <= N && house[x + 1][y] == 0)
            dfs(x + 1, y, 1);
    }

    if (x + 1 <= N && y + 1 <= N && house[x][y + 1] == 0 && house[x + 1][y] == 0 && house[x + 1][y + 1] == 0)
        dfs(x + 1, y + 1, 2);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &house[i][j]);

    dfs(1, 2, 0);
    printf("%d", ans);
}
