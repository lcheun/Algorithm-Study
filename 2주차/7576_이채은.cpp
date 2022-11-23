#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int M, N, ans = 0, box[1001][1001];

bool check_tomato(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j] == 0) return false;
        }
    }
    
    return true;
}

int main(){
    queue<pair<int, int>> tomato;
    
    scanf("%d %d", &M, &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1) tomato.push({i, j});
        }
    }
    
    while(!tomato.empty() && !check_tomato()){
        int q_size = tomato.size(); ans++;
        
        for(int i=0; i<q_size; i++){
            auto tmp = tomato.front(); tomato.pop();
            for(int j=0; j<4; j++){
                int ny = tmp.first + dy[j];
                int nx = tmp.second + dx[j];
                if(ny >= 0 && ny < N && nx >=0 && nx < M && box[ny][nx] == 0) {
                    box[ny][nx] = 1;
                    tomato.push({ny, nx});
                }
            }
        }
    }
    
    if(!check_tomato()) ans = -1;
    printf("%d", ans);
}
