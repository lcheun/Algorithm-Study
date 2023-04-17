//
// Created by KangMinji on 2023-04-17.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<bool, int> ci;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0 ,1, -1};
int n, m;

bool check(int x, int y){
	return (x >= 0 || y >= 0 || x < m || y < n);
}

bool checkFinish(vector<vector<int>> &board, int x, int y){
	for (int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny) && board[nx][ny]){
			return false;
		}
	}
	return true;
}

ci solve(vector<vector<int>> &board, int mx, int my, int yx, int yy){
	if (checkFinish(board, mx, my)){ // 1번 조건 : 이동할 수 없는 경우 패배
		return {false, 0};
	}
	if (mx == yx && my == yy){ // 2번 조건 : 동일 발판에 있을 때 내가 먼저 이동하면 승리
		return {true, 1};
	}

	bool is_win = false;
	int min_cnt = 1e9-1, max_cnt = 0;

	for (int i=0; i<4; i++){
		int nx = mx + dx[i];
		int ny = my + dy[i];

		if (!check(nx, ny) || !board[nx][ny]){
			continue;
		}

		board[nx][ny] = 0;
		ci next = solve(board, yx, yy, nx, ny);
		board[nx][ny] = 1;

		cout << next.first << ' ' << next.second;

		if (!next.first){ // 상대가 진다면
			is_win = true;
			min_cnt = min(min_cnt, next.second + 1); // 현재->다음으로 가는 1턴 추가
		} else {
			max_cnt = max(max_cnt, next.second + 1);
		}
	}
	return {is_win, (is_win ? min_cnt : max_cnt)};
}

// 1) 상하좌우 4칸이 모두 발판 X || 이동할 수 없는 경우
// 2) 같은 발판 위에 있엇는데, 상대 플레이어가 먼저 다른 발판으로 이동한 경우
// 이길 수 있으면 최대한 빨리 이김 & 질 수 밖에 없다면 최대한 늦게 짐
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	n = board.size();
	m = board[0].size();

	ci answer = solve(board, aloc[0], aloc[1], bloc[0], bloc[1]);
	cout << answer.first << ' ' << answer.second;
	return answer.second;
	return 0;
}