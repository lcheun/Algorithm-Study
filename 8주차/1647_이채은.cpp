#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second) return true;
        else if (a.second == b.second) return a.first > b.first;
        else return false;
    }
};

int N, M, del = 0, ans = 0;
bool visit[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
vector<pair<int, int>> path[100001];


int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        path[x].push_back({ y, z });
        path[y].push_back({ x, z });
    }
    pq.push({ 1, 0 });
    while (!pq.empty()) {
        pair<int, int> p = pq.top();  pq.pop();
        if (!visit[p.first]) {
            ans += p.second;
            if (p.second > del) del = p.second;
            visit[p.first] = true;
            for (pair<int, int> tmp : path[p.first]) {
                if (!visit[tmp.first]) pq.push(tmp);
            }
        }
    }
    printf("%d", ans - del);
}
