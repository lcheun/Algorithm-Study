#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    int visited[100001] = {};
    q.push(N); visited[N] = 1;
    
    while(!q.empty()) {
        int p = q.front(); q.pop();
        if(p == K) break;
        
        if(p>0 && visited[p-1] == 0){
            q.push(p-1);
            visited[p-1] = visited[p] + 1;
        }
        
        if(p<100000 && visited[p+1] == 0){
            q.push(p+1);
            visited[p+1] = visited[p] + 1;
        }
        
        if(p<=50000 && visited[p*2] == 0){
            q.push(p*2);
            visited[p*2] = visited[p] + 1;
        }
    }
    
    cout << visited[K] - 1 << '\n';
}
