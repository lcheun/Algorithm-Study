#include <iostream>
#include <string>

using namespace std;

int n, m, ans = 0;
string word;

// I 한 번 나오면 n 개수만큼 OI가 나올 때마다 답 ++
int main() {
    cin >> n >> m >> word;
    
    for(int i=1;i<word.size();i++) {
        int count = 0;
        if(word[i-1]=='I') {
            while(word[i]=='O' && word[i+1]=='I') {
                i += 2;
                count++;
                if(count==n) {
                    count--;
                    ans++;
                }
            }
        }
    }
    
    cout << ans << '\n';
}
