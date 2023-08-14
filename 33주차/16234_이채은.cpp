#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>

using namespace std;

int N, L, R, cnt;
bool flag;
int A[50][50];
bool visit[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void move(int x, int y) {
    visit[x][y] = true;
    set<pair<int, int>> s;
    queue<pair<int, int>> q;
    int sum = A[x][y];
    q.push({ x, y });
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        visit[p.first][p.second] = true;
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
                int gap = abs(A[p.first][p.second] - A[nx][ny]);
                if (gap >= L && gap <= R) {
                    visit[nx][ny] = true;
                    q.push({ nx, ny });
                    s.insert({ nx, ny });
                    sum += A[nx][ny];
                    flag = true;
                }
            }
        }
    }
    if (!flag) return;
    s.insert({ x, y });
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        pair<int, int> p = *iter;
        A[p.first][p.second] = sum / s.size();
    }
}

int main() {
    scanf("%d%d%d", &N, &L, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    while (true) {
        flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j]) continue;
                move(i, j);
            }
        }
        if (!flag) break;
        cnt++;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visit[i][j] = false;
    }
    printf("%d", cnt);
}
