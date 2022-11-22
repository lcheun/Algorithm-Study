#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N, M, u, v, ans = 0;
    vector<int> graph[1001];
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    queue<int> q;
    bool visit[1001] = {false, };
    for(int i=1; i<=N; i++){
        if(visit[i]) continue;
        q.push(i); ans++;
        while(!q.empty()){
            int tmp = q.front(); q.pop();
            for(int node : graph[tmp]){
                if(visit[node]) continue;
                q.push(node);
                visit[node] = true;
            }
        }
    }
    
    printf("%d", ans);
}
