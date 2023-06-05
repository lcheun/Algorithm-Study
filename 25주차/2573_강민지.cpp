// 골드4
// Created by KangMinji on 2023-05-29.
// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

int n, m;
vector<vector<int>> board;
vector<vector<int>> tmp_board;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isRange(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void meltIce(){
	// 그냥 board에 바로 반영하면 안 되고 한 턴 지날 때 한꺼번에 반영해줘야 함
	tmp_board.assign(n, vector<int>(m, 0));

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (!board[i][j]){
				continue;
			}
			// 동서남북에 있는 0의 개수 count
			int zero_cnt = 0;
			for (int k=0; k<4; k++){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (isRange(nx, ny) && board[nx][ny] == 0){
					zero_cnt++;
				}
			}

			tmp_board[i][j] = board[i][j] - zero_cnt;
			tmp_board[i][j] = tmp_board[i][j] < 0 ? 0 : tmp_board[i][j];
		}
	}

	board = tmp_board;
//	for (int i=0; i<n; i++){
//		for (int j=0; j<m; j++){
//			cout << board[i][j];
//		}
//		cout << '\n';
//	}
//	cout << "\n";
}

void check(int a, int b){
	queue<ci> q;

	// 초기화
	q.push({a, b});
	visited[a][b] = true;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visited[nx][ny] && isRange(nx, ny) && board[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	// 입력
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	// 빙산이 다 녹았다면 0
	int time = 0;
	while(true){
		int ice_cnt = 0;
		visited.assign(n, vector<bool>(m, false));

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (!visited[i][j] && board[i][j]){
					check(i, j);
					ice_cnt++;
				}
			}
		}

//		printf("===== ice_cnt : %d\n", ice_cnt);
		if (ice_cnt == 0){ // 빙산 다 녹은 경우
			cout << 0;
			break;
		}

		if (ice_cnt >= 2){ // 빙산 분리된 경우
			cout << time;
			break;
		}
		time++;
		meltIce();
	}
}