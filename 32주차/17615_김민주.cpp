#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, cnt, ans = 1e9;
string s;

// 1. 빨간 공 왼쪽으로
// 2. 빨간 공 오른쪽으로
// 3. 파란 공 왼쪽으로
// 4. 파란 공 오른쪽으로
void solve(char type) {
    cnt = 0; // 바꿔야되는 공 개수
    bool flag = false;
    
    //왼쪽
    for(int i=0;i<s.size();i++) {
        if(s[i]!=type) flag = true; // s[i]가 다른 색이면 true로 바꿈(분기점)
        else if(flag&&s[i]==type) cnt++; // 위치 바꿈
    }
    
    if(ans>cnt) ans = cnt;
    flag = false;
    cnt = 0;
    
    //오른쪽
    for(int i=s.size()-1;i>=0;i--) {
        if(s[i]!=type) flag = true;
        else if(flag&&s[i]==type) cnt++;
    }
    
    if(ans>cnt) ans = cnt;
}

int main() {
    cin >> n;
    cin >> s;
    
    solve('R');
    solve('B');
    
    cout << ans << "\n";
    
    return 0;
}
