#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int m, n, cnt = 0, max1 = 0, max2 = 0;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[50][50];
bool visit[50][50];

int bfs(int x, int y) {
    int area = 1;
    queue<pair<int, int>> q;
    visit[x][y] = true; q.push({ x, y });
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            if (!(map[p.first][p.second] >> i & 1)) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    q.push({ nx, ny });
                    area++;
                }
            }
        }
    }
    return area;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                int num = bfs(i, j);
                max1 = (num > max1) ? num : max1;
                cnt++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 1; k <= 8; k *= 2) {
                if (map[i][j] & k) {
                    map[i][j] -= k;
                    memset(visit, false, sizeof(visit));
                    int num = bfs(i, j);
                    max2 = (num > max2) ? num : max2;
                    map[i][j] += k;
                }
            }
        }
    }

    printf("%d\n%d\n%d", cnt, max1, max2);
}
