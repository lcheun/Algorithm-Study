#include <stdio.h>
#include <queue>
#include <vector>
#include <stdbool.h>
#include <utility>

using namespace std;

int N, M, a, b, c;
vector<pair<int, int>> com[1001];
bool visit[1001] = { false, true, false, };

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        com[a].push_back({ b, c });
        com[b].push_back({ a, c });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    for (int i = 0; i < com[1].size(); i++) {
        q.push({ com[1][i].first, com[1][i].second });
    }

    int ans = 0;
    pair<int, int> p;
    while (!q.empty()) {
        p = q.top();
        q.pop();
        if (visit[p.first]) continue;
        visit[p.first] = true;
        ans += p.second;
        int node = p.first;
        for (int i = 0; i < com[node].size(); i++) {
            q.push({ com[node][i].first, com[node][i].second });
        }
    }

    printf("%d", ans);
}
