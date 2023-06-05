// 골드2
// Created by KangMinji on 2023-05-24.
// https://www.acmicpc.net/problem/9576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

// 범위 크기로 비교하면 안 된다!
// 반례 : 1
//4 4
//1 2
//2 3
//3 4
//1 3
// 4
bool cmp(const ci &a, const ci &b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int t, n, m, a, b;

	cin >> t;
	while(t--){
		// 입력
		cin >> n >> m;
		vector<bool> books(n+1, false);
		vector<ci> application_list;

		while(m--) {
			cin >> a >> b;
			application_list.push_back({a, b});
		}
		sort(application_list.begin(), application_list.end(), cmp);

		// 연산
		int answer = 0;
		for (ci application : application_list){
			for (int i = application.first; i<=application.second; i++){
				// 책 받을 수 있는 경우
				if (!books[i]){
					books[i] = true;
					answer++;
					break;
				}
			}
		}

		// 출력
		cout << answer << '\n';
	}
}