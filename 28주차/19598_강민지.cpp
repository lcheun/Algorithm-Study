// 골드5
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/19598

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int n;
vector<ci> time;
priority_queue<int, vector<int>, greater<>> pq; // 종료 시간 저장


int main() {
	cin >> n;
	time.assign(n, {});

	for (int i=0; i<n; i++){
		cin >> time[i].first >> time[i].second;
	}
	sort(time.begin(), time.end());

	pq.push(time[0].second);

	int answer = 1;
	for (int i=1; i<n; i++){
		while(!pq.empty() && pq.top() <= time[i].first)
			pq.pop();
		pq.push(time[i].second);
		answer = max(answer, (int)pq.size());
	}
	cout << answer;
}