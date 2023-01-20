// 실버2
// Created by KangMinji on 2023-01-20.
// https://www.acmicpc.net/problem/18111

#include <iostream>
using namespace std;
const int MAX = 501;

int board[MAX][MAX] = {0,};
int n, m, b;

pair<int, int> calcMaxHeight() {
	int min_time = 6.4 * 2 * 1e7;
	int best_height = -1;

	for (int height = 0; height <= 256; height++) {
		// 채우는 횟수, 제거하는 횟수
		int add_cnt = 0, rm_cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int h = board[i][j] - height;
				if (h > 0) {
					rm_cnt += h;
				} else if (h < 0) {
					add_cnt -= h; // h 음수라서 제거해야 함!
				}
			}
		}
		// 블록으로 채울 수 있는 경우
		if (rm_cnt + b >= add_cnt) {
			int time = rm_cnt * 2 + add_cnt;
			// 그냥 >로만 하면 height update x
			if (min_time >= time){
				min_time = time;
				best_height = height;
			}
		}
	}
	return {min_time, best_height};
}

/*
 * 가로 m, 세로 n, 시작 (0, 0)
 * 위에 있는 블록 제거 2초
 * 블록 꺼내기 1초
 */
int main() {
	// 입력
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	cout << calcMaxHeight().first << " " << calcMaxHeight().second;

}