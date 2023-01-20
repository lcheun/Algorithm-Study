// 실버1
// Created by KangMinji on 2023-01-20.
// https://www.acmicpc.net/problem/16198

#include <iostream>
#include <vector>
using namespace std;

vector<int> e;
int max_energy = -1;

/*
1) x번째 에너지 구슬 선택 후 제거
(첫 번째와 마지막 에너지 구슬은 선택 불가)
2) w(x-1) * w(x+1)의 에너지 모으기
3) n--
4) 에너지 구슬 번호 재정렬(1~n)
*/
void dfs(int sum) {
	if (e.size() == 2) {
		max_energy = max(max_energy, sum);
		return;
	}
	// 첫 번째와 마지막 구슬 제외
	for (int i = 1; i < e.size() - 1; i++) {
		int energy = e[i - 1] * e[i + 1];
		int tmp = e[i]; // 따로 변수 지정 안 해주면 erase 한 후라 e[i] 값이 바뀜!!

		e.erase(e.begin() + i);
		dfs(sum + energy);
		e.insert(e.begin() + i, tmp);
	}
}

int main() {
	int n, w;

	// 입력
	cin >> n;
	while(n--){
		cin >> w;
		e.push_back(w);
	}

	// 연산
	dfs(0);
	cout << max_energy;

	return 0;
}