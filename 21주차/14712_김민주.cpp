#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<bool>> visited(26, vector<bool>(26, false));
int dx[3] = {-1, 0, -1};
int dy[3] = {0, -1, -1};
int N, M;

//2x2안만들어지는지 확인
bool check(int x, int y) {
    int cnt = 0;
    for(int i=0;i<3;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(0<=nx&&nx<N&&0<=ny&&ny<M){
            if(visited[nx][ny]) cnt++;
        }
    }
    if(cnt==3) return false;
    else return true;
}

int answer = 0;
void dfs(int x, int y) {
    // 끝까지 다 돌았으면 answer+1
    if(x==N-1&&y==M){
        answer++;
        return;
    }
    
    if(y==M) {
        y=0;
        x++;
    }
    
    // 이 칸에 둔다. -> 2x2 안 만들어지는 경우에만 다음으로
    visited[x][y] = true;
    if(check(x, y)) dfs(x, y+1);
    // 이 칸에 안 둔다
    visited[x][y] = false;
    dfs(x, y+1);
}

int main() {
    cin >> N;
    cin >> M;
    
    dfs(0, 0);
    cout << answer;
}
