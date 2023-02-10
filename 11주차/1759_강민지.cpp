// 골드5 / 브루트포스 & 백트래킹
// Created by KangMinji on 2023-02-10.
// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alpha;
vector<char> answer;

bool check() {
	int vowel_cnt = 0;

	for (int i=0; i<l; i++){
		if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'o'
			|| answer[i] == 'u' || answer[i] == 'i'){
			vowel_cnt++;
			continue;
		}
	}

	if (vowel_cnt >= 1 && l-vowel_cnt >= 2){
		return true;
	}
	return false;
}

void backtracking(int cnt, int idx) {
	if (cnt == l && check()) {
		for (char c : answer){
			cout << c;
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < c; i++) {
		answer.push_back(alpha[i]);
		backtracking(cnt + 1, i + 1);
		answer.pop_back();
	}
}

int main() {

	// 입력
	cin >> l >> c;
	alpha.assign(c, 0);
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}

	// 연산
	sort(alpha.begin(), alpha.end());

	backtracking(0, 0);
}