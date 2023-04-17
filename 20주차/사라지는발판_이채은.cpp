#include <algorithm>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int N, M;
bool visited[5][5];
vector<vector<int>> map;

//패배 짝수 승리 홀수
int solve(int cury, int curx, int opy, int opx){
    if(vis[cury][curx]) return 0;    
  
    int ret = 0;
    for(int i=0; i<4; i++){
        int ny = cury + dy[i];
        int nx = curx + dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || !map[ny][nx]) continue;
      
        visited[cury][curx] = true;
        int val = solve(opy, opx, ny, nx) + 1;      
        visited[cury][curx] = false;        
        
        if(ret % 2 == 0 && val % 2 == 1) ret = val;
        else if(ret % 2 == 0 && val % 2 == 0) ret = max(ret, val); 
        else if(ret % 2 == 1 && val % 2 == 1) ret = min(ret, val);
        
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size();
    M = board[0].size();
    block = map;
  
    return solve(aloc[0], aloc[1], bloc[0], bloc[1]);
}
