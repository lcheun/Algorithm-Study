// 골드4
// Created by KangMinji on 2023-03-13.
// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <set>
using namespace std;

int main() {
	int t, k, n;
	char op;

	cin >> t;
	while(t--){
		multiset<int> ms;
		// 입력
		cin >> k;
		while(k--) {
			cin >> op >> n;

			// 연산
			switch (op) {
				case 'I':
					ms.insert(n);
					break;
				case 'D':
					if (ms.empty()) {
						break;
					}
					if (n == 1) { // 최댓값 삭제
						ms.erase(--ms.end()); // ms.end() : 맨 끝 값 다음의 주소를 반환
					}
					if (n == -1) { // 최솟값 삭제
						ms.erase(ms.begin());
					}
					break;
			}
		}

		// 출력
		if (ms.empty()){
			cout << "EMPTY\n";
		} else {
			cout << *(--ms.end()) << ' ' << *ms.begin() << '\n'; // ms.begin, end는 iterator 반환
		}
	}
}