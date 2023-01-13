//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int N;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool isRange(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void bfs(int r, int c, int height) {
    queue<ci> q;

    // 방문 체크
    visited[r][c] = true;
    q.push({r, c});

    // 인접 체크
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = a + dr[i];
            int nc = b + dc[i];
            if (isRange(nr, nc) && !visited[nr][nc] && board[nr][nc] > height) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    // 입력
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    int max_height = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    // 연산
    int max_cnt = -1;
    // 비의 양을 다르게 함
    // 🔥 모든 영역이 물에 안 잠기는 경우도 있음 -> k=0부터 시작해야 함
    for (int height = 0; height < max_height; height++) {
        visited.assign(N, vector<bool>(N, false));

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && board[i][j] > height) {
                    bfs(i, j, height);
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    // 출력
    cout << max_cnt << "\n";
}