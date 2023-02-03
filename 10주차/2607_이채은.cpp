#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1;

    int alpha[26] = { 0, };
    for(char c : s1) {
        alpha[c-'A'] += 1;
    }
        
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> s2;
        
        if(abs((int)s1.size() - (int)s2.size()) >= 2) continue;
        
        int comp[26];
        copy(alpha, alpha + 26, comp);

        int cnt_s = 0;
        for(char c : s2) {
            if (comp[c - 'A'] > 0) {
                comp[c - 'A']--;
                cnt_s++;
            }
        }
        
        if(abs(cnt_s - (int)s1.size()) <= 1 && abs(cnt_s - (int)s2.size()) <= 1) cnt++;
    }

    cout << cnt << '\n';
}
