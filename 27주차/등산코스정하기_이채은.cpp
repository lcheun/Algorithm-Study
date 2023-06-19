#include <string>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>

using namespace std;

int dist[50001];
bool summit[50001];

//path - 등산로, gate - 출입구, summit - 산봉우리

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    vector<pair<int, int>> adj[50001];
    for(auto p : paths){
        adj[p[0]].push_back({p[2], p[1]});
        adj[p[1]].push_back({p[2], p[0]});
    }
    
    for(auto s : summits){
        summit[s] = true;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> v;
    memset(dist, -1, sizeof(dist));
    
    for(int g : gates) {
        pq.push({0, g});
        dist[g] = 0;
    }
    
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int cur = tmp.second;
        
        if(tmp.first > dist[cur]) continue;
        
        if(summit[cur]){
            v.push_back(tmp); continue;
        }
        
        for(auto p : adj[cur]){
            if(dist[p.second] == -1 || max(tmp.first, p.first) < dist[p.second]){
                dist[p.second] = max(tmp.first, p.first);
                pq.push({dist[p.second], p.second});
            }
        }
        
    }
    
    sort(v.begin(), v.end());
    answer.push_back(v[0].second);
    answer.push_back(v[0].first);
    
    return answer;
}
