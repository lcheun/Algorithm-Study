#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, S, T, ans;
priority_queue<int, vector<int>, greater<int>> endTime;
vector<pair<int, int>> time;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return (a.second < b.second);
    else return (a.first < b.first);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &S, &T);
        time.push_back({ S, T });
    }

    sort(time.begin(), time.end(), cmp);

    for (auto p : time) {
        if (!endTime.empty() && endTime.top() <= p.first) endTime.pop();
        endTime.push(p.second);
    }
    printf("%d", endTime.size());
}
