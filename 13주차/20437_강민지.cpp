// 골드5
// Created by KangMinji on 2023-02-23.
// https://www.acmicpc.net/problem/20437

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -1;

int main() {
	int t, k;
	string w;
	vector<int> alphabet[26];

	// 입력
	cin >> t;
	while(t--){
		cin >> w >> k;

		// 0) 초기화
		int min_len = MAX;
		int max_len = MIN;
		for (int i=0; i<26; i++){
			alphabet[i].clear();
		}

		// 1) 알파벳 개수 count(해당 문자의 idx 배열)
		for (int i=0; i<w.length(); i++){
			alphabet[w[i]-97].push_back(i);
		}

		// 2) 알파벳 개수 k개 이상인 것부터 sliding window 출발
		for (int i=0; i<26; i++){
			int a_size = alphabet[i].size();
			if (a_size >= k){
				// sliding window 시작 idx
				for (int j=0; j<=a_size-k; j++){
					int len = alphabet[i][j+k-1] - alphabet[i][j] + 1;
					min_len = min(min_len, len);
					max_len = max(max_len, len);
				}
			}
		}

		// 3) 출력
		if (min_len == MAX || max_len == MIN){
			cout << -1 << "\n";
		} else {
			cout << min_len << " " << max_len << "\n";
		}
	}
}