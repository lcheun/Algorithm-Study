#include <iostream>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int dist[1001][1001];
int dp[1001];
vector<pair<int, int>> adj[1001];

int dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
    pq.push({0, start});
    dist[start][start] = 0;
 
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
 
        if(cur.first > dist[start][cur.second]) continue;
        for(auto item: adj[cur.second]) {
            int ndist = cur.first + item.second;
            
            if (ndist < dist[start][item.first]) {
                dist[start][item.first] = ndist;
                pq.push({ndist, item.first});
            }
        }
    }
 
    return dist[start][2];
}

int memo(int v) {
    if(v == 2) return 1;
 
    int ret = dp[v];
 
    if(ret != -1) return ret;
    ret = 0;
 
    for (auto item: adj[v])
        if (dist[v][2] > dist[item.first][2])
            ret += memo(item.first);
    
    return ret;
}

 
int main() {
    memset(dp, -1, sizeof(dp));
    fill(&dist[0][0], &dist[0][0] + 1001 * 1001, 2147483647);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
 
    for(int i = 1; i <= N; ++i) dijkstra(i);
 
    cout << memo(1);
}
