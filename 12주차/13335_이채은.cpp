#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int n, w, L;
    int truck[1000];
    queue<int> q;
    scanf("%d %d %d", &n, &w, &L);
    for (int i = 0; i < n; i++)
        scanf("%d", &truck[i]);

    int cnt = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        while (true) {
            if (q.size() == w) {
                cur -= q.front();
                q.pop();
            }
            if (truck[i] + cur <= L) break;
            q.push(0);
            cnt++;
        }
        q.push(truck[i]);
        cur += truck[i];
        cnt++;
    }

    printf("%d", cnt + w);
}
