#include <iostream>

using namespace std;

int N, ans;
int A[1000], dp[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                tmp = (tmp > dp[j]) ? tmp : dp[j];
            }
        }
        dp[i] = tmp + 1;
        ans = (ans > dp[i]) ? ans : dp[i];
    }
    cout << ans << '\n';
}
