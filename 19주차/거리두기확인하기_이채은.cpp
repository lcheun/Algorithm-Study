#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
       
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    queue<pair<int,pair<int,int>>> q;
    
    for(auto place : places) {
        bool flag = false;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(place[i][j]=='P') {
                    bool visit[5][5] = {false, };
                    visit[i][j] = true;
                    q.push({0, {i, j}});
                  
                    while(!q.empty()) {
                        auto p = q.front(); q.pop();
                        int len = p.first;
                        int y = p.second.first;
                        int x = p.second.second;

                        for(int d=0; d<4; d++) {
                            int ny = y + dy[d];
                            int nx = x + dx[d];
                            if(ny>=0 && ny<5 && nx>=0 && nx<5 && !visit[ny][nx] && place[ny][nx] != 'X') {
                                visit[ny][nx]=true;
                                if(place[ny][nx]=='P') {
                                    if(len <= 1) flag=true;
                                }
                                else if(place[ny][nx]=='O') {
                                    q.push({len+1, {ny,nx}});
                                }
                            }
                        }
                    }
                }
                
            }
        }
      
        if(flag) answer.push_back(0);
        else answer.push_back(1);
        
    }
    
    return answer;
}
