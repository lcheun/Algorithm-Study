#include <iostream>
#include <algorithm>

using namespace std;

int N, K, ans = 500000;
int small[20];
int big[20];

void energy(int idx, int val, bool chk) {
    if (idx == N) ans = min(ans, val);
    if (idx >= N) return;
    energy(idx + 1, val + small[idx], chk);
    energy(idx + 2, val + big[idx], chk);
    if (!chk) {
        energy(idx + 3, val + K, true);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> small[i] >> big[i];
    cin >> K;
    energy(1, 0, false);
    cout << ans << endl;
}
