#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
 
int N, M, ans = 1000;
vector<pair<int, int>> emp;
int map[20][20];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool visited[20][20];

bool check(){
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

void bfs(int fst, int sec) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(emp[fst]); q.push(emp[sec]);
    visited[emp[fst].first][emp[fst].second] = true;
    visited[emp[sec].first][emp[sec].second] = true;
    
    int time = 0;
    while(!q.empty()){
        int iter = (int) q.size();
        for(int i=0; i<iter; i++) {
            auto tmp = q.front(); q.pop();
            for(int j=0; j<4; j++){
                int ny = tmp.first + dy[j];
                int nx = tmp.second + dx[j];
                if(ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
        time++;
        if(check()) break;
    }
    
    ans = min(time, ans);
}

void select(){
    int s = (int) emp.size();
    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++){
            bfs(i, j);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &map[i][j]);
            emp.push_back({i, j});
        }
    }
    
    select();
    cout << ans;
}
