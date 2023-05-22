#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int coin[21];
int dp[10001];

void init(){
    for(int i=0; i<10001; i++)
        dp[i] = 0;
}

void solve(int N, int M){
    dp[0] = 1;
    for(int i=0; i<N; i++){
        for(int j=coin[i]; j<=M; j++){
            dp[j] += dp[j-coin[i]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> coin[j];
        }
        
        int M;
        cin >> M;
        solve(N, M);
        
        cout << dp[M] << '\n';
        init();
    }

}
