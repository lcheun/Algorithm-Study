#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int k; cin >> k; // 챕터 수
        long long ans = 0;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq; // 우큐

        while (k--) {
            int num;
            cin >> num;
            pq.push(num);
        }
        
        // 챕터 크기 순으로 정렬하고 모든 챕터가 하나의 파일로 합쳐질 때까지
        // 크기가 가장 작은 챕터 두개를 하나의 파일로 합침
        while(!pq.empty()) {
            if(pq.size() == 1) break; //파일 하나 남으면 멈춤
            long long first = pq.top(); pq.pop(); // 크기가 가장 작은 챕터 큐에서 pop
            long long second = pq.top(); pq.pop(); // 두번째로 작은 챕터
            
            ans += first + second;
            pq.push(first+second);
        }
        
        pq.pop();
        cout << ans << '\n';
    }
    
    return 0;
}
