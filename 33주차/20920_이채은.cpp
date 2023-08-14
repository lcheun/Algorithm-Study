#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> m;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        else return a.first.length() > b.first.length();
    }
    else return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (str.length() < M) continue;
        if (m.find(str) == m.end())
            m.insert({ str, 0 });
        else m[str]++;
    }

    vector<pair<string, int>> tmp(m.begin(), m.end());
    sort(tmp.begin(), tmp.end(), cmp);

    for (auto p : tmp)
        cout << p.first << '\n';
}
