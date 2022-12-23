#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<string>

using namespace std;
 
string s, e;
set<string> visited;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int BFS() {
    queue<pair<string, int>> q;
    q.push({s, 0});
    visited.insert(s);
 
    while (q.empty() == 0) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
 
        if (cur == e) return cnt;
        
        int zero = cur.find('0');
        int x = zero / 3;
        int y = zero % 3;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
                string next = cur;
                swap(next[x * 3 + y], next[nx * 3 + ny]);
 
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next,cnt + 1});
                }
            }
        }
    }
    return -1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    e = "123456780";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a; cin >> a;
            char tmp = a + '0';
            s = s + tmp;
        }
    }
    cout << BFS() << '\n';
}
