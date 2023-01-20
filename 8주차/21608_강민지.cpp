// 골드5
// Created by KangMinji on 2023-01-20.
// https://www.acmicpc.net/problem/21608
// 참고 : https://velog.io/@sin5015243/%EB%B0%B1%EC%A4%80-21608-%EC%83%81%EC%96%B4-%EC%B4%88%EB%93%B1%ED%95%99%EA%B5%90-Python

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> like;
vector<int> order;
vector<int> satisfaction = {0, 1, 10, 100, 1000};

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct seat {
	int r, c;
	int cnt_like = 0, cnt_blank = 0;
};

/*
 *  비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
 */
bool cmp(const seat &a, const seat &b){
	// 1) 좋아하는 학생과 인접한 칸이 많은 순서대로
	if (a.cnt_like != b.cnt_like){
		return a.cnt_like > b.cnt_like;
	}
	// 2) 비어있는 칸이 가장 많은 칸으로
	if (a.cnt_blank != b.cnt_blank){
		return a.cnt_blank > b.cnt_blank;
	}
	// 3) 행의 번호가 가장 적은 칸으로
	if (a.r != b.r){
		return a.r < b.r;
	}
	// 4) 열의 번호가 가장 적은 칸으로
	if (a.c != b.c){
		return a.c < b.c;
	}
}

bool checkBoard(int nr, int nc){
	return (nr <= n) && (nr > 0) && (nc <= n) && (nc > 0);
}

int countLike(int r, int c){
	int sum = 0;
	int st = board[r][c]; // 자리에 앉아있는 학생의 번호

	for (int i=0; i<4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		// 0) 범위 확인
		if (!checkBoard(nr, nc)) {
			continue;
		}
		// 1) 좋아하는 학생과 인접한 칸의 개수
		auto like_it = find(like[st].begin(), like[st].end(), board[nr][nc]);
		if (like_it != like[st].end()) {
			sum++;
		}
	}
	return sum;
}

void findSeatInfo(int r, int c, int st, vector<seat> &v) {
	int cnt_like = 0, cnt_blank = 0;

	for (int i=0; i<4; i++){
		int nr = r + dx[i];
		int nc = c + dy[i];

		// 0) 범위 확인
		if (!checkBoard(nr, nc)){
			continue;
		}
		// 1) 좋아하는 학생과 인접한 칸의 개수
		auto like_it = find(like[st].begin(), like[st].end(), board[nr][nc]);
		if (like_it != like[st].end()){
			cnt_like++;
		}
		// 2) 비어있는 칸의 개수
		if (board[nr][nc] == 0){
			cnt_blank++;
		}
	}
	v.push_back({r, c, cnt_like, cnt_blank});
}

int main() {
	int st, l1, l2, l3, l4;

	// 입력
	cin >> n;
	board.assign(n+1, vector<int>(n+1, 0));
	like.assign(n*n+1, vector<int>());
	for (int i = 0; i < n * n; i++) {
		cin >> st >> l1 >> l2 >> l3 >> l4;
		like[st].push_back(l1);
		like[st].push_back(l2);
		like[st].push_back(l3);
		like[st].push_back(l4);
		order.push_back(st);
	}

	// 연산
	// 1) 자리 계산
	for (int order_st : order) {
		vector<seat> v;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 자리가 비어있는 경우에만 앉힘
				if (board[i][j] != 0) {
					continue;
				}
				findSeatInfo(i, j, order_st, v);
			}
		}
		sort(v.begin(), v.end(), cmp);
		board[v[0].r][v[0].c] = order_st;
	}

	// 2) 만족도 계산
	int answer = 0;
	for (int r=1; r<=n; r++){
		for (int c=1; c<=n; c++){
			int sum = countLike(r, c);
			answer += satisfaction[sum];
		}
	}
	cout << answer;
}