// 실버2 / 이분탐색(좌표압축)
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/17829

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[1024][1024];

int findSecondMax(int x, int y, int len){
	vector<int> v;
	for (int i=x; i<x+len; i+=(len/2)){
		for (int j=y; j<y+len; j+=(len/2)){
			v.push_back(board[i][j]);
		}
	}
	sort(v.begin(), v.end());
	return v[v.size()-2];
}

void compress(int len){
	if (len > n){
		cout << board[0][0] << "\n";
		return;
	}

	for (int i=0; i<n; i+=len){
		for (int j=0; j<n; j+=len){
			board[i][j] = findSecondMax(i, j, len);
		}
	}
	compress(len*2);
}

int main() {

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	compress(2);
}