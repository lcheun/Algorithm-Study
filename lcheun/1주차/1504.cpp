#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int N, E, V1, V2;
vector<pair<int, int>> graph[801];
vector<int> dist;
 
int dijkstra(int s, int e){
    dist = vector<int>(N+1, 1e9+7);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    q.push({s, 0});
    dist[s] = 0;
    
    while(!q.empty()){
        auto p = q.top(); q.pop();
        
        if(p.second > dist[p.first]) continue;
        
        for(int i = 0; i < graph[p.first].size(); i++){
            int next = graph[p.first][i].first;
            int cost = graph[p.first][i].second + p.second;
            
            if(cost < dist[next]){
                dist[next] = cost;
                q.push({next, cost});
            }
        }
    }
    
    return dist[e];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> E;
    
    int a, b, c;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    cin >> V1 >> V2;
    
    int res1, res2;
    int a1 = dijkstra(1, V1);
    int a2 = dijkstra(V1, V2);
    int a3 = dijkstra(V2, N);
    
    if(a1 == 1e9+7 || a2 == 1e9+7 || a3 == 1e9+7) res1 = 1e9+7;
    else res1 = a1 + a2 + a3;
    
    int b1 = dijkstra(1, V2);
    int b2 = dijkstra(V2, V1);
    int b3 = dijkstra(V1, N);
    if(b1 == 1e9+7 || b2 == 1e9+7 || b3 == 1e9+7) res2 = 1e9+7;
    else res2 = b1 + b2 + b3;
    
    if(min(res1, res2) == 1e9+7) cout << -1;
    else cout << min(res1, res2);
    
}
 
