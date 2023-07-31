#include <iostream>
#include <algorithm>

using namespace std;

char ball[500005];
int N, cnt, ans, redCnt, blueCnt;

int main(){
    cin >> N >> ball;
  
    for(int i = 0; i < N; i++) {
        if (ball[i] == 'R') redCnt++;
        else blueCnt++;
    }
    ans = min(redCnt, blueCnt);

    for(int i = 0; i < N; i++) {
        if (ball[i] != ball[0]) break;
        cnt++;
    }
    if (ball[0] == 'R') ans = min(ans, redCnt - cnt);
    else ans = min(ans, blueCnt - cnt);

    cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if (ball[i] != ball[N - 1]) break;
        cnt++;
    }

    if (ball[N - 1] == 'R') ans = min(ans, redCnt - cnt);
    else ans = min(ans, blueCnt - cnt);

    cout << ans;
}
