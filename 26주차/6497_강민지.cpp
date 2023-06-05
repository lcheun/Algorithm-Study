// 골드4
// Created by KangMinji on 2023-06-05.
// https://www.acmicpc.net/problem/6497

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

int findParent(int x) {
	if (parent[x] < 0) { //값이 음수면 루트 정점
		return x;
	}
	return parent[x] = findParent(parent[x]); //그래프 압축하며 루트 정점 찾기
}

bool unionNodes(int x, int y){
	int px = findParent(x);
	int py = findParent(y);

	if (px == py){
		return false;
	}

	if (parent[px] < parent[py]) {  //새로운 루트 px
		parent[px] += parent[py];
		parent[py] = px;
	} else { //새로운 루트 py
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

int kruskal(int v, vector<tp> &edges){
	int sum = 0, cnt = 0;

	for (tp edge : edges){
		 int w = get<0>(edge);
		 int n1 = get<1>(edge);
		 int n2 = get<2>(edge);
		if (!unionNodes(n1, n2)){ // 사이클이 생기는 경우
			continue;
		}
		sum += w;
		cnt++;

		if (cnt == v-1){ // 필요한 간선 모두 찾은 경우
			return sum;
		}
	}
	// MST 못 만든 경우
	return 0;
}

int main() {
	int n, m, x, y, z;

	// 입력
	while(cin >> m >> n){
		if (n == 0 && m == 0){
			break;
		}

		int total = 0;
		vector<tp> edge;
		parent.assign(m+1, -1);

		while(n--){
			cin >> x >> y >> z;
			edge.push_back({z, x, y});
			total += z;
		}
		sort(edge.begin(), edge.end());

		// 연산
		int min_cost = kruskal(m, edge);

		// 출력
		cout << total - min_cost << "\n";
	}
}