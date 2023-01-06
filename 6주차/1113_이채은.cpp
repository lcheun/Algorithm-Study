#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, h = 0, ans = 0;
int map[55][55];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue <pair<int, int>> q;

void bfs(int val) {
    map[0][0] = val;
    q.push({ 0,0 });
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny>=0 && ny<=N+1 && nx>=0 && nx<=M+1 && map[ny][nx]<val) {
                map[ny][nx] = val;
                q.push({ ny,nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &map[i][j]);
            if(map[i][j] > h) h = map[i][j];
        }
    }
    
    for(int i=1; i<=h; i++) {
        bfs(i);
        cout << i << ' ';
        for(int j=1; j<=N; i++) {
            for(int k=1; k<=M; k++) {
                if(map[j][k] < i) {
                    ans += 1;
                    map[j][k] += 1;
                }
            }
        }
    }
    
    cout << ans << '\n';
}
