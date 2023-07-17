#include <stdio.h>

int N, M, ans = 1;
int seat[40];
int dp[41] = { 1, 1, 2, };

void set() {
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &seat[i]);
    }
    set();
    int start = 0;
    for (int i = 0; i < M; i++) {
        int end = seat[i];
        ans *= dp[end - start - 1];
        start = end;
    }
    ans *= dp[N-start];
    printf("%d", ans);
}
