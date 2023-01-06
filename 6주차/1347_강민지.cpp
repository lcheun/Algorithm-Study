//
// Created by KangMinji on 2023-01-06.
//

#include <iostream>

using namespace std;
const int MAX = 101;
const int START = 50;

char board[MAX][MAX]; // {#, } 안 됨
int dir = 0; // 방향(남, 서, 북, 동) - 시계방향
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
int min_r = START, min_c = START, max_r = START, max_c = START;

void updateCoord(int nr, int nc) {
//    if (isMin) {
        min_r = min(min_r, nr);
        min_c = min(min_c, nc);
//    } else {
        max_r = max(max_r, nr);
        max_c = max(max_c, nc);
//    }
}

void changeLeft() {
    dir--;
    if (dir < 0) { // 인덱스 오류
        dir += 4;
    }
}

void changeRight() {
    dir++;
    dir %= 4;
}

/*
 * 미로의 최대 범위 : 101*101
 * 홍준이는 (50, 50)에서 시작한다고 가정
 * 0) 미로를 #로 채워놓고 홍준이가 지나간 곳만 .으로 바꾼다
 * 1) 미로의 좌측 하단, 우측 상단 좌표를 이용해 미로의 일부분만 출력한다
 * (최소 r, c좌표 / 최대 r, c 좌표)
 */
int main() {
    int n;
    char c;

    // 초기값 설정
//    fill(&board[0][0], &board[MAX][MAX], '#');
    // https://velog.io/@neity16/BOJ-1347-%EB%AF%B8%EB%A1%9C-%EB%A7%8C%EB%93%A4%EA%B8%B0-C
    for (auto &i: board) {
        fill(i, i + MAX, '#');
    }
    board[START][START] = '.';
    int nr = START, nc = START;

    // 입력 & 연산
    cin >> n;
    while (n--) {
        cin >> c;
        if (c == 'F') {
            nr += dr[dir];
            nc += dc[dir];
            board[nr][nc] = '.';
            updateCoord(nr, nc);
//            if (dir < 2) {
//                updateCoord(nr, nc, true);
//            } else {
//                updateCoord(nr, nc, false);
//            }
        } else if (c == 'R') {
            changeRight();
        } else {
            changeLeft();
        }
    }

    // 출력
    for (int i = min_r; i <= max_r; i++) {
        for (int j = min_c; j <= max_c; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}