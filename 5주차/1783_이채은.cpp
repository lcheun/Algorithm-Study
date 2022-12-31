#include <iostream>
#include <algorithm>

using namespace std;
 
int N, M, ans;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    
    if (N == 1) ans = 1;
    else if (N == 2) ans = min(4, (M + 1)/2);
    else if (M < 7) ans = min(4, M);
    else ans = M - 2;
    
    cout << ans;
 
}
