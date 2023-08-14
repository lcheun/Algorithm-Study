#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D, map[10001];
vector<pair<int, int>> road[10001];

int main(){
    cin >> N >> D;
    
    int f, t, v;
    for(int i=0; i<N; i++){
        cin >> f >> t >> v;
        road[t].push_back({f, v});
    }
    
    for(int i=1; i<10001; i++) map[i] = 987654321;
    
    for(int i=1; i<=D; i++){
        if(road[i].size() == 0){
            map[i] = map[i-1] + 1; continue;
        }
        for(auto e : road[i]){
            map[i] = min(map[i], min(map[i-1] + 1, map[e.first] + e.second));
        }
    }
    
    cout << map[D];
}
