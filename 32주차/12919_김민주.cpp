#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

string temp = "";

// 탐색 가능한 경우의 수를 줄이기 위해 거꾸로!
void solve(string S, string T) {
    if(S==T) {
        cout << 1 << "\n";
        exit(0);
    }
    
    if(S.size() >= T.size()) return;
    if(T[T.size()-1]=='A') {
        temp = T;
        temp.erase(temp.size()-1);
        solve(S, temp);
    }
    
    if(T[0]=='B') {
        temp = T;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        solve(S, temp);
    }
    
}

int main() {
    string S; cin >> S;
    string T; cin >> T;
    
    solve(S, T);
    cout << 0 << "\n";
    return 0;
}
