#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long dp[10][65];
long long ans[65];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<10; i++) dp[i][1] = 1;
    for(int i=2; i<=64; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                dp[j][i] += dp[k][i-1];
            }
        }
    }
    
    for(int i=1; i<=64; i++){
        for(int j=0; j<10; j++){
            ans[i] += dp[j][i];
        }
    }
    
    int T, n;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        cout << ans[n] << '\n';
    }
}
