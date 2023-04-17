// 실버1
// Created by KangMinji on 2023-04-17.
// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m, num;

	// 입력
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<>> pq;
	while (n--) {
		cin >> num;
		pq.push(num);
	}

	// 연산
	while (m--) {
		long long n1 = pq.top();
		pq.pop();
		long long n2 = pq.top();
		pq.pop();

		pq.push(n1 + n2);
		pq.push(n1 + n2);
	}

	// 출력
	long long ans = 0;
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}

	cout << ans << "\n";
}
