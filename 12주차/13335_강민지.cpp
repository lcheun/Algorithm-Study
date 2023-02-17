// 실버1
// Created by KangMinji on 2023-02-17.
// https://www.acmicpc.net/problem/13335

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n, w, L;

	// 입력
	cin >> n >> w >> L;
	vector<int> weight(n, 0);

	for (int i=0; i<n; i++){
		cin >> weight[i];
	}

	// 연산
	int answer = 0, total = 0;
	queue<int> q; // 다리 위에 있는 트럭의 하중 총합

	for (int i=0; i<n; i++){

		// 다리 길이만큼 빈 칸 넣기
		while(true){
			if (q.size() == w){
				total -= q.front();
				q.pop();
			}
			if (total + weight[i] <= L){
				break;
			}
			q.push(0);
			answer++;
		}
		q.push(weight[i]);
		total += weight[i];
		answer++;
	}

	// 출력
	cout << answer + w << "\n";
}