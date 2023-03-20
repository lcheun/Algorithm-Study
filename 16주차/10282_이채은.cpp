
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

int infect; 
int time; 

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int n) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, INF);

	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = -pq.top().first; 
		int cur = pq.top().second; 

		pq.pop();

		for (auto &p : graph[cur]) {
			int next = p.first;
			int next_dist = p.second + cur_dist; 

			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.emplace(-dist[next], next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			infect += 1;
			if (dist[i] > time) time = dist[i];
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int n, d, c;
    cin >> n >> d >> c;

		vector<pair<int, int>> hack[n + 1];
		for (int i = 0; i < d; i++) {
			int a, b, s;
      cin >> a >> b >> s;
			hack[b].push_back({a, s});
		}

		infect = 0;
		time = 0;
		dijkstra(hack, c, n);
    
    cout << infect << " " << time;
	}

	return 0;
}
