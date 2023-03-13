//
// Created by KangMinji on 2023-03-13.
// https://school.programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

long long binarySearch(int n, ll low, ll high, vector<int> &times){
	long long answer = 0;

	while(low <= high){
		ll mid = (low + high) / 2;

		ll cnt = 0; // mid 시간 동안 처리할 수 있는 사람 수
		for (int i=0; i<times.size(); i++){
			cnt += mid / times[i];
		}

		if (cnt >= n){
			high = mid - 1;
			answer = mid;
		} else {
			low = mid + 1;
		}
	}
	return answer;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());
	answer = binarySearch(n, 1, (ll)times.back() * n, times); // high할 때 ll 안 하면 자료형 오류

	return answer;
}