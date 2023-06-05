#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    for(int i=2; i<=N; i++){
        for(int j=2; j<=K; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % 1000000003;
        }
    }
    
    cout << (dp[N-1][K] + dp[N-3][K-1]) % 1000000003;
}
