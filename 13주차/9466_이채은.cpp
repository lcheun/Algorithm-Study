#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int t, n, cnt;
int graph[100001];
bool visited[100001];
bool done[100001];


void check(int node) {
	visited[node] = true;
	int next = graph[node];
	
	if (!visited[next]) check(next);
	else if (!done[next]) {
		for (int i = next; i != node; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}
	done[node] = true;
}


int main() {
  
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
    
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) check(i);
		}
		cout << n-cnt << '\n';
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
	}

}
