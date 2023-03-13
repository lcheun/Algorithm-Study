#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double x, y, ans;
int connect[101];
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> vec;

int find(int a) {
    if (a == connect[a]) return a;

    return connect[a] = find(connect[a]);
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        star.push_back({ x, y });
    }

    for (int i = 0; i < star.size(); i++) {
        for (int j = i + 1; j < star.size(); j++) {
            double cost = dist(star[i].first, star[i].second, star[j].first, star[j].second);
            vec.push_back({ cost, {i, j} });
        }
    }

    for (int i = 0; i < n; i++)
        connect[i] = i;

    sort(vec.begin(), vec.end());

    for (auto tmp : vec) {
        double cost = tmp.first;

        int a = find(tmp.second.first);
        int b = find(tmp.second.second);

        if (a != b) {
            connect[a] = b;
            ans += cost;
        }
    }

    printf("%.2f\n", ans);
}
