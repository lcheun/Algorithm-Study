// 골드4
// Created by KangMinji on 2023-01-20.
// https://www.acmicpc.net/problem/1647

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;
vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

bool unionNode(int x, int y) {
	int px = findParent(x);
	int py = findParent(y);

	if (px == py) {
		return false;
	}

	if (parent[px] < parent[py]) {
		parent[px] += parent[py];
		parent[py] = px;
	} else {
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

int kruskal(int n, vector<tp> &edge) {
	int sum = 0, cnt = 0;
	for (auto [w, u, v]: edge) {
		// 둘이 같은 집합에 있는 경우
		if (!unionNode(u, v)) {
			continue;
		}
		sum += w;
		cnt++;

		// 0부터 n-1 => n-2개의 간선
		if (cnt == n - 1) {
			return sum;
		}
	}
	// ST 못 만든 경우
	return 0;
}

/*
1) 최소 신장 트리를 만들고
2) 제일 큰 가중치 가지는 도로 삭제 -> 제일 마지막에 들어오는 애가 제일 크다!
=> 따라서 n-2개의 간선만 체크
*/
int main() {
	int n, m, a, b, c;

	// 입력
	cin >> n >> m;

	vector<tp> edge;
	parent.assign(n + 1, -1);

	while (m--) {
		cin >> a >> b >> c;
		edge.push_back({c, a, b});
	}

	// 연산
	sort(edge.begin(), edge.end());

	// 연산 & 출력
	cout << kruskal(n - 1, edge);

	return 0;
}