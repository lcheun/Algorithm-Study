#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, T;
string W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> W >> K;
        int shrt = 100000, lng = -1;
        vector<int> pos[26];
        for (int j = 0; j < W.size(); j++) {
            pos[W[j] - 'a'].push_back(j);
        }
        for (int j = 0; j < 26; j++) {
            if (pos[j].size() < K) continue;
            int cnt = 0, first = 0, last = K - 1;
            while (last < pos[j].size()) {
                shrt = min(shrt, pos[j][last] - pos[j][first] + 1);
                lng = max(lng, pos[j][last] - pos[j][first] + 1);
                first++; last++;
            }
        }
        if (lng == -1) printf("-1\n");
        else printf("%d %d\n", shrt, lng);
    }
}
