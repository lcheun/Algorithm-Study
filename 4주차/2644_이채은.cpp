#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, s, e, m, ans;
vector<int> family[101];
int visited[101];

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s >> e >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    
    queue<int> q;
    q.push(s); visited[s] = 1;
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        if(tmp == e) break;
        
        for(int p : family[tmp]){
            if(visited[p] == 0){
                q.push(p);
                visited[p] = visited[tmp] + 1;
            }
        }
    }
    
    cout << visited[e] - 1 << '\n';
}
