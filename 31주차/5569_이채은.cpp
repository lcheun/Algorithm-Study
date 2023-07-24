#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int w, h, dp[101][101][2][2];
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> w >> h;
    
    for(int i=1; i<101; i++){
        dp[i][1][0][0] = 1;
        dp[1][i][1][0] = 1;
    }
    
    for(int i=2; i<=h; i++){
        for(int j=2; j<=w; j++){
            dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % 100000;
            dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % 100000;
            dp[i][j][0][1] = dp[i-1][j][1][0];
            dp[i][j][1][1] = dp[i][j-1][0][0];
        }
    }
    
    cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % 100000;
    
}
 

 

