#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, K, ans;
bool alphabet[26];
vector<char> basic = { 'a', 'n', 't', 'i', 'c' };
vector<string> list;

int test()
{
    bool chk;
    int cnt = 0;
    for (string s:list) {
        chk = true;
        for (int j = 0; j < s.length(); j++) {
            if (!alphabet[s[j] - 'a']) {
                chk = false; break;
            }
        }

        if (chk) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt) {
    if (cnt == K) {
        ans = max(ans, test()); return;
    }

    for (int i = idx; i < 26; i++) {
        if (alphabet[i]) continue;
        alphabet[i] = true;
        dfs(i + 1, cnt + 1);
        alphabet[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        list.push_back(s);
    }

    if (K < 5) {
        cout << 0 << '\n';
        exit(0);
    }

    for (char c : basic) alphabet[c - 'a'] = true;
    K -= 5;

    dfs(0, 0);
    cout << ans << '\n';
}
