// 골드2
// Created by KangMinji on 2023-02-23.
// https://www.acmicpc.net/problem/1655

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;

	// 입력
	cin >> n;

	bool max_flag = true;
	priority_queue<int, vector<int>> max_heap;
	priority_queue<int, vector<int>, greater<>> min_heap;

	while(n--){
		cin >> num;

		// 1) insert
//		if (max_heap.size() == min_heap.size()){
//			max_heap.push(num);
//		} else {
//			min_heap.push(num);
//		}
		if (max_flag){
			max_heap.push(num);
		} else {
			min_heap.push(num);
		}
		max_flag = !max_flag;

		// 2) operate : swap하는 경우
		// empty 조건을 앞쪽에 넣어야 한다
		if ((!max_heap.empty() && !min_heap.empty()) && max_heap.top() > min_heap.top()){
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}

		// 3) print
		cout << max_heap.top() << "\n";
	}
}