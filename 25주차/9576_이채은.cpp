#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int student[1001], book[1001];
pair<int, int> adj[1001];
bool visited[1001];

bool dfs(int a){
    visited[a] = true;
    for(int i=adj[a].first; i<=adj[a].second; i++){
        if(book[i] == -1 || (!visited[book[i]] && dfs(book[i]))){
            student[a] = i;
            book[i] = a;
            return true;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, M;
    cin >> T;
    
    while(T-- > 0){
        cin >> N >> M;
        
        int a, b, ans = 0;
        for(int i=1; i<=M; i++){
            cin >> a >> b;
            adj[i] = {a, b};
        }
        
        fill(book, book+N+1, -1);
        fill(student, student+M+1, -1);
        for(int i=1; i<=M; i++){
            if(student[i] == -1){
                fill(visited, visited+N, 0);
                if(dfs(i)) ans++;
            }
        }
        
        cout << ans << '\n';
    }
}
