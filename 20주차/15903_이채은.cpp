#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long> pq;
int n, m, num;
long long ans;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n >> m;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        pq.push(-num);
    }
  
    for(int i=0; i<m; i++) {
        long long first = -pq.top(); pq.pop();
        long long second = -pq.top(); pq.pop();
        long long sum = first + second;
        pq.push(-sum);
        pq.push(-sum);
    }
    
    while (!pq.empty()) {
        ans += (-pq.top());
        pq.pop();
    }
  
    cout << ans;
}
