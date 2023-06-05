#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int s, x, y;
int map[201][201];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<pair<int, pair<int, int>>> virus;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
            if(map[i][j] != 0)
                virus.push_back({map[i][j], {i, j}});
        }
    }
    cin >> s >> y >> x;

    sort(virus.begin(), virus.end());
 
    int time = 0;
    while(time < s){
        int cnt = virus.size();
      
        for(int i = 0; i < cnt; i++){
            int y = virus[i].second.first;
            int x = virus[i].second.second;

            for(int d = 0; d < 4; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];

                if(ny >= 1 && nx >= 1 && ny <= n && nx <= n) continue;
                if(map[ny][nx]) continue;

                map[ny][nx] = virus[i].first;
                virus.push_back({virus[i].first, {ny, nx}});
            }
        }
      
        if(map[y][x]) break;
        time++;
    }
    
    cout << map[y][x] << '\n';
}
