#include <iostream>
#include <algorithm>

using namespace std;

int N;
char board[51][51];
int ans;

void countColumn() {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N; j++) {
            if(arr[i][j] == arr[i][j+1]) cnt++;
            else {
                if(cnt > ans) ans = cnt;
                cnt = 1;
            }
        }
    }
}

void countRow() {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N; j++) {
            if(arr[j][i] == arr[j+1][i]) cnt++;
            else {
                if(cnt > ans) ans = cnt;
                cnt = 1;
            }
        }
    }
}

int main() {
    cin >> N;
    
    for(int  i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int  i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize - 1; j++) {
            swap(board[i][j], board[i][j+1]);
            countRow(board, boardSize);
            countColumn(board, boardSize);
            swap(board[i][j+1], board[i][j]);
            
            swap(board[j][i], board[j+1][i]);
            countRow(board, boardSize);
            countColumn(board, boardSize);
            swap(board[j][i], board[j+1][i]);
        }
    }
    
    cout << ans << '\n';
}
