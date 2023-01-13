//
// Created by KangMinji on 2023-01-13.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;
int answer;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isRange(int x, int y){
    return (x>=0 && x<N) && (y>=0 && y<M);
}

void backtracking(int x, int y, int depth, int sum){
    // 종료조건
    if (depth == 4){
        answer = max(answer, sum);
        return;
    }

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isRange(nx, ny)){
            continue;
        }

        int temp = board[nx][ny];
        board[nx][ny] = 0;
        //2) 보라색은 DEPTH 3까지 하고 이전 좌표로 돌아와서 DEPTH 1로 추가 탐색해야 함
        // -> DEPTH 2일 때 추가 탐색하면 된다!
        if (depth == 2){
            backtracking(x, y, depth+1, sum+temp);
        }
        backtracking(nx, ny, depth+1, sum+temp);
        board[nx][ny] = temp;
    }
}

/*
 * 테트로미노는 회전이나 대칭 가능
 * 1) 보라색 제외 모양들은 DEPTH 4에서 가능
 * 2) 보라색은 DEPTH 3까지 하고 이전 좌표로 돌아와서 DEPTH 1로 추가 탐색해야 함
 */
int main() {

    // 입력
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    // 연산
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int temp = board[i][j];

            // 백트래킹
            board[i][j] = 0;
            backtracking(i, j, 1, temp);
            board[i][j] = temp;
        }
    }

    // 출력
    cout << answer << "\n";

}