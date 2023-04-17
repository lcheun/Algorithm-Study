//
// Created by KangMinji on 2023-04-17.
//

#include <string>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

// pop & insert가 1회
// 최대 범위 long long
int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -2;

	queue<int> q1, q2;
	for (int n : queue1){ q1.push(n); }
	for (int n : queue2){ q2.push(n); }

	long long sum1 = accumulate(begin(queue1), end(queue1), 0ll);
	long long sum2 = accumulate(begin(queue2), end(queue2), 0ll);

	// 불가능한 경우
	if ((sum1 + sum2) % 2 == 1){
		return -1;
	}

	int cnt = 0;
	int s1 = q1.size(), s2 = q2.size();
	while(sum1 != sum2){
		if (cnt > s1 + s2 + 2){ // 종료 조건이 애매....
			return -1;
		}
		if (sum1 < sum2){
			q1.push(q2.front());
			sum1 += q2.front();
			sum2 -= q2.front();
			q2.pop();
		} else {
			q2.push(q1.front());
			sum2 += q1.front();
			sum1 -= q1.front();
			q1.pop();
		}
		cnt++;
	}

	return cnt;
}