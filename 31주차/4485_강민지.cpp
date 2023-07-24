// 골드4
// Created by KangMinji on 2023-07-24.
// https://www.acmicpc.net/problem/4485

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> ci;

int n;
int loopy[126][126];
int board[126][126];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dijkstra() {
	priority_queue<pair<int, ci>> pq;

	pq.push({-board[0][0],{0, 0}});
	loopy[0][0] = board[0][0];

	while(!pq.empty()){
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int cost = board[nx][ny];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (loopy[nx][ny] > loopy[x][y] + cost){
				loopy[nx][ny] = loopy[x][y] + cost;
				pq.push({-loopy[nx][ny], {nx, ny}});
			}
		}
	}
}

int main() {
	int test = 1;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		for (int i=0; i<126; i++)
			fill(loopy[i], loopy[i]+126, 999);

		dijkstra();

		cout << "Problem " << test++ << ": " << loopy[n-1][n-1] << '\n';
	}
}