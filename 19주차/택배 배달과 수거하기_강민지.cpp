//
// Created by KangMinji on 2023-04-10.
//

#include <string>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> ci;

void checkMaxBox(stack<ci> &st, int cap){
	int cnt = 0;
	while(!st.empty()){
		// 배송할 수 있는지 확인
		ci d = st.top();
		st.pop();
		if (cnt + d.second <= cap){
			cnt += d.second;
		} else {
			d.second -= (cap - cnt);
			st.push(d);
			break;
		}
	}
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;
	stack<ci> deliver, pickup; // {집 위치, 상자 개수}

	for (int i=0; i<n; i++){
		if (deliveries[i]){
			deliver.push({i+1, deliveries[i]});
		}
	}

	for (int i=0; i<n; i++){
		if (pickups[i]){
			pickup.push({i+1, pickups[i]});
		}
	}

	// 제일 뒤에서부터 배달 진행
	while(true){
		// 배달 종료되는 경우
		if (deliver.empty() && pickup.empty()){
			break;
		}
		// 이동 거리 계산
		long long deliver_idx = deliver.empty() ? 0 : deliver.top().first;
		long long pickup_idx = pickup.empty() ? 0 : pickup.top().first;
		answer += max(deliver_idx, pickup_idx) * 2;

		// 1) 배송
		checkMaxBox(deliver, cap);

		// 2) 수거
		checkMaxBox(pickup, cap);
	}
	return answer;
}