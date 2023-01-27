//
// Created by KangMinji on 2023-01-27.
//

#include <iostream>

using namespace std;

int main() {
	int x1, x2, y1, y2, p1, p2, q1, q2;
	int xl, xr, yl, yr, xdiff, ydiff;

	// 입력
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> p1 >> q1;
		cin >> x2 >> y2 >> p2 >> q2;

		// 연산
		xl = max(x1, x2);
		xr = min(p1, p2);
		yl = max(y1, y2);
		yr = min(q1, q2);

		xdiff = xr - xl;
		ydiff = yr - yl;

		char answer;
		if (xdiff > 0 && ydiff > 0) { // 1) 직사각형
			answer = 'a';
		} else if (xdiff < 0 || ydiff < 0) { // 2) 공통부분 없음
			answer = 'd';
		} else if (xdiff == 0 && ydiff == 0) { // 3) 점
			answer = 'c';
		} else { // 4) 선분
			answer = 'b';
		}

		// 출력
		cout << answer << "\n";
	}

}