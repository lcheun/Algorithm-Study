// 실버1
// Created by KangMinji on 2023-02-23.
// https://www.acmicpc.net/problem/6588

#include <iostream>

using namespace std;
const int MAX = 1000001;
bool not_prime[MAX];

void findPrime() {
	for (int i = 2; i * i < MAX; i++) {
		if (!not_prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				not_prime[j] = true;
			}
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;

	findPrime();

	while (true) {
		cin >> num;

		if (!num) {
			break;
		}

		bool can_make = false;
		for (int i = 3; i < num; i += 2) { // 홀수만 해당
			if (!not_prime[num - i] && !not_prime[i]) {
				cout << num << " = " << i << " + " << num - i << "\n";
				can_make = true;
				break;
			}
		}

		if (!can_make) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}