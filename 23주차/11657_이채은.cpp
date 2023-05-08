#include<iostream>
#include<vector>
 
using namespace std;
 
int N, M;
long long dist[510];
vector<pair<pair<int, int>, int>> edge;

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    for (int i=1; i<=N; i++) dist[i] = 987654321;
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge.push_back{{a, b}, c});
    }
  
    dist[1] = 0;
    for(int i=1; i <=N-1; i++) {
        for(auto tmp : edge) {
            if(dist[tmp.first.first] == 987654321) continue;
            if(dist[tmp.first.second] > dist[tmp.first.first] + tmp.second) dist[tmp.first.second] = dist[tmp.first.first] + tmp.second;
        }
    }
 
    for(auto tmp : edge) {
        if(dist[tmp.first.first] == 987654321) continue;
        if(dist[tmp.first.second] > dist[tmp.first.first] + tmp.second) {
            cout << -1 << '\n';
            return;
        }
    }
 
    for(int i=2; i<=N; i++) {
        if (dist[i] == 987654321) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
 
}
