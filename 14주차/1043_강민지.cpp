// 골드4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node){
	if (parent[node] < 0){ // 음수값이면 루트 정점
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp){
		return;
	}

	if (parent[xp] < parent[yp]){
		parent[xp] += parent[yp];
		parent[yp] = xp;
	} else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int countLie(vector<int> &party){
	int answer = 0;
	for (int person : party){
		if (findParent(person) != findParent(0)){
			answer++;
		}
	}
	return answer;
}

int main() {
	int n, m, cnt, person, first_person;

	// 입력
	cin >> n >> m;
	parent.assign(n+1, -1);

	// 1) 진실 아는 사람 tree 생성
	cin >> cnt;
	while(cnt--){
		cin >> person;
		unionInput(0, person);
	}

	vector<int> party;
	while(m--){
		cin >> cnt >> first_person;

		party.push_back(first_person);
		cnt--;

		while(cnt--){
			cin >> person;
			unionInput(first_person, person);
		}
	}

	// 연산 : party 돌면서 거짓말 할 수 있는지 확인
	cout << countLie(party);
}