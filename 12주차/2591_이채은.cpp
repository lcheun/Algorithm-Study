#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    string str;
    int dp[100] = {1, 0, };
    cin >> str;
    
    for(int i=1; i<str.size(); i++){
        if(((str[i] - '0') + (str[i-1] - '0') * 10) <= 34 && str[i-1] != '0'){
            if(i == 1) dp[i] = 1;
            else dp[i] = dp[i-2];
        }
        if(str[i] != '0') dp[i] += dp[i-1];
    }
    
    cout << dp[str.size() - 1];
}
