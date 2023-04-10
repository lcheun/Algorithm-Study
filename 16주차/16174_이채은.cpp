#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int map[65][65];
bool check[65][65];
pair<int, int> Move[2] = {{1, 0}, {0, 1}};

bool bfs(int X, int Y){
    queue<P> q;
    check[X][Y] = true;
    q.push({X, Y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(map[x][y] == -1) return true;
        for(int i = 0; i < 2; i++){
            int nx = x + Move[i].first * map[x][y];
            int ny = y + Move[i].second * map[x][y];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
                if(check[nx][ny]) continue;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
	cin >> N;
  
	for(int i = 1; i <= N; i++){
	    for(int j = 1; j <= N; j++){
	        cin >> map[i][j];
	    }
	}
  
	if(bfs(1, 1)) cout << "HaruHaru";
  else cout << "Hing";
}
