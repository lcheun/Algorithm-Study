#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C, ans = 0;
bool alphabet[26];
char board[20][20];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void backtracking(int y, int x, int cnt) {
    int idx = board[y][x] - 'A';
    alphabet[idx] = true;
    ans = max(cnt, ans);
    
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >=0 && ny < R && nx >= 0 && nx < C && !alphabet[board[ny][nx] - 'A']){
            backtracking(ny, nx, cnt + 1);
        }
    }
    
    alphabet[idx] = false;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        string row;
        cin >> row;
        for(int j=0; j<C; j++){
            board[i][j] = row[j];
        }
    }
    
    backtracking(0, 0, 1);
    
    cout << ans << '\n';
}
