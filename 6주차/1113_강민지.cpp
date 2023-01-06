//
// Created by KangMinji on 2023-01-06.
//

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ci;
const int MAX = 52;

int board[MAX][MAX];
queue<ci> q;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int n, m;
int max_height = 0;
int ans = 0;

bool isInside(int x, int y) {
    return (x >= 0) && (x <= m + 1) && (y >= 0) && (y <= n + 1);
}

void bfs(int height) {
    board[0][0] = height;
    q.push({0, 0});

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx += dx[i];
            ny += dy[i];
            if (isInside(nx, ny) && board[nx][ny] < height) {
                board[nx][ny] = height;
                q.push({nx, ny});
            }
        }
    }
}

/*
 * bfs 사용하는 문제
 * 1) 수영장의 최대 높이 탐색
 * 2) for int i=1; i<=최대 높이
 * 2-1) 테두리의 높이가 모두 i보다 작은 부분 발견 -> 물 채우기
 *
 */
int main() {
    // 입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &board[i][j]);
//            cin >> board[i][j]; 숫자 연속으로 붙어있으면 입력 X
            max_height = max(max_height, board[i][j]);
        }
    }

    // 연산
    // 1) 수영장 높이 1 ~ 최대 높이까지 돌면서
    for (int height = 1; height <= max_height; height++) {
        cout << "***" << height << "  \n";
        // 2) 기존 지역 넓히기 -> 값 height로 변경
        bfs(height); // 해당 높이인 부분을 탐색

        // 3) 신규 지역 탐색
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j] < height) {
                    ans++;
                    board[i][j]++;
                }
            }
        }
        cout << "###" << ans << "\n";
    }

    // 출력
    cout << ans << "\n";
}