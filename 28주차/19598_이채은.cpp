#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, cnt, ans;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int s, e;
    for(int i = 0; i < N; i++) {
        cin >> s >> e;
        v.push_back({ s, 1 });
        v.push_back({ e, -1 });
    }
    
    sort(v.begin(), v.end());
    
    for(auto p : v) {
        cnt += p.second;
        ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
}
