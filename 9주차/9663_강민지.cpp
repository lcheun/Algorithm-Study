// 골드4
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/9663

#include <iostream>
using namespace std;
const int SIZE = 15;

bool col[SIZE];
bool right_dig[SIZE*2]; // col + row
bool left_dig[SIZE*2]; 	// col - row + N
int N;
int answer = 0;

void nqueen(int row){
	if (row == N){
		answer++;
		return;
	}
	for (int i=0; i<N; i++){
		if (!col[i] && !right_dig[row+i] && !left_dig[i-row+N]){
			col[i] = right_dig[row+i] = left_dig[i-row+N] = true;
			nqueen(row+1);
			col[i] = right_dig[row+i] = left_dig[i-row+N] = false;
		}
	}
}

/*
 * 1) 상하좌우로 존재 x(행,열 중복 x)
 * 2) 우상 대각선 X
 * 3) 좌하 대각선 X
 */
int main() {

	// 입력
	cin >> N;

	// 연산
	nqueen(0);

	// 출력
	cout << answer << "\n";
}