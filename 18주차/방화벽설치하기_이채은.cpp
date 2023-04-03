#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans;
int map[9][9];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> blank, fire;


void spread(){
    int map_copy[9][9];
    bool visit[9][9] = {false, };
    copy(&map[0][0], &map[0][0]+81, &map_copy[0][0]);

    queue<pair<int, int>> q;
    for(auto p : fire){
        q.push(p); visit[p.first][p.second] = true;
    }

    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int ny = p.first + dy[k];
            int nx = p.second + dx[k];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && !visit[ny][nx] && map_copy[ny][nx] != 1){
                q.push({ny, nx}); map_copy[ny][nx] = 2; visit[ny][nx] = true;
            }
        }
    }

    int tmp = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map_copy[i][j] == 0) tmp++;
        }
    }

    ans = max(ans, tmp);
}

void build_wall(int idx, int t){
    if(t == 3){
        spread(); return;
    }

    for(int i=idx; i<blank.size(); i++){
        auto p = blank[i];
        map[p.first][p.second] = 1;
        build_wall(i+1, t+1);
        map[p.first][p.second] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) blank.push_back({i, j});
            if(map[i][j] == 2) fire.push_back({i, j});
        }
    }

    build_wall(0, 0);
    cout << ans;
}
