#include <stdio.h>
#include <algorithm>

using namespace std;
int N, K, W, V;
int dp[101][100001] = { {0, 0}, };

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W, &V);
        for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - W >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
        }
    }
    printf("%d", dp[N][K]);
}
