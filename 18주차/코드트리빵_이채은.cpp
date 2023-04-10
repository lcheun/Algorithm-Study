#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, map[16][16];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
bool visited[16][16];
vector<pair<int, int>> cs;
queue<pair<pair<int, int>, int>> ppl;

void search(int num){
    int ty = n+1, tx = n+1;
    bool visited_tmp[16][16], flag = false;
    copy(&visited[0][0], &visited[0][0]+256, &visited_tmp[0][0]);

    queue<pair<int, int>> q;
    q.push(cs[num]); visited_tmp[cs[num].first][cs[num].second] = true;
    while(!q.empty()){
        int s = q.size();
        for(int i=0; i<s; i++){
            auto p = q.front(); q.pop();
            for(int j=3; j>=0; j--){
                int ny = p.first + dy[j];
                int nx = p.second + dx[j];
                if(ny >= 1 && nx >= 1 && ny <= n && nx <= n && !visited_tmp[ny][nx]){
                    if(map[ny][nx] == 1){
                        flag = true;
                        if(ny < ty || (ny == ty && nx < tx)){
                            ty = ny; tx = nx;
                        }
                    }
                    q.push({ny, nx}); visited_tmp[ny][nx] = true;
                }
            }
        }
        if(flag) break;
    }

    visited[ty][tx] = true;
    ppl.push({{ty, tx}, num});
}

void move(int sy, int sx, int num){
    bool visited_tmp[16][16];
    copy(&visited[0][0], &visited[0][0]+256, &visited_tmp[0][0]);

    int ey = cs[num].first;
    int ex = cs[num].second;
    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i<4; i++){
        int ty = sy + dy[i];
        int tx = sx + dx[i];
        if(ty >= 1 && ty <= n && tx >= 1 && tx <= n && !visited[ty][tx]){
            if(ty == ey && tx == ex){
                visited[ty][tx] = true; return;
            }
            q.push({{ty, tx}, i});
            visited_tmp[ty][tx] = true;
        }
    }
    
    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = p.first.first + dy[i];
            int nx = p.first.second + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= n && !visited_tmp[ny][nx]){
                if(ny == ey && nx == ex){
                    ppl.push({{sy+dy[p.second], sx+dx[p.second]}, num});
                    return;
                }
                q.push({{ny, nx}, p.second}); 
                visited_tmp[ny][nx] = true;
            }
        }
    }
}

int simulation(){
    int t = 0;
    while(true){
        int s = ppl.size();
        for(int i=0; i<s; i++){
            auto p = ppl.front(); ppl.pop();
            move(p.first.first, p.first.second, p.second);
            
        }
        if(t < m) search(t);
        t++;

        if(ppl.size() == 0) break;
    }

    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int y, x;
        cin >> y >> x;
        cs.push_back({y, x});
    }

    cout << simulation();
}
