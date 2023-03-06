#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

#define INF 2147483647

using namespace std;

int N, M, cost[100000];
bool arr[100000];
vector<pair<int, int>> graph[100000];

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int a, b, t;
    for(int i=0; i<M; i++){
        cin >> a >> b >> t;
        if((arr[a] || arr[b]) && (a != N-1 && b != N-1)) continue;
        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto p : graph[0]) pq.push(p);
    for(int i=1; i<N; i++) cost[i] = INF;
    
    while(!pq.empty()){
        int val = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost[cur] < val) continue;
        
        for(auto p : graph[cur]){
            if(cost[p.second] > val + p.first){
                cost[p.second] = val + p.first;
                pq.push({cost[p.second], p.first});
            }
        }
    }
    
    if (cost[N - 1] == INF) cout << -1;
    else cout << cost[N - 1];
}
