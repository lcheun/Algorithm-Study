#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;

bool check(int idx, int num) {
    int y = blank[idx].first;
    int x = blank[idx].second;
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][x] == num || sudoku[y][i] == num) return false;
    }

    int sy = (y / 3) * 3, sx = (x / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[sy + i][sx + j] == num) return false;

    sudoku[y][x] = num;
    return true;
}

void solve(int idx) {
    if (idx == blank.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (int i = 1; i < 10; i++) {
        if (check(idx, i)) {
            solve(idx + 1);
            sudoku[blank[idx].first][blank[idx].second] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0) blank.push_back({ i, j });
        }
    }

    solve(0);
}
