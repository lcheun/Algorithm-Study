#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, val[1001], dp[1001];
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> val[i];
    }
    
    for(int i=1; i<=N; i++){
        dp[i] = val[i];
        for(int j=1; j<i; j++){
            dp[i] = min(dp[i], dp[i-j] + dp[j]);
        }
    }
    
    cout << dp[N] << '\n';
}
