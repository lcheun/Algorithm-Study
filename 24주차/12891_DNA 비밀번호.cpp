//
// Created by KangMinji on 2023-05-22.
//

#include <iostream>
#include <map>
using namespace std;

char alpha[4] = {'A', 'C', 'G', 'T'};
map<char, int> info;

bool isSuccess(map<char, int> t) {
	for(auto iter = info.begin(); iter != info.end(); ++iter) {
		if(iter->second != 0) {
			if(t.find(iter->first) != t.end()) {
				if((iter->second) <= t[iter->first]) continue;
				else return false;
			} else return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	int S, P;

	cin >> S >> P;
	string str;
	cin >> str;
	for(int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		info[alpha[i]] = n;
	}

	// init
	map<char, int> m;
	for(int i = 0; i < P; ++i) {
		m[str[i]] += 1;
	}
	if(isSuccess(m)) ans += 1;

	for(int i = P; i < S; ++i) {
		m[str[i - P]] -= 1;
		m[str[i]] += 1;
		if(isSuccess(m)) ans += 1;
	}
	cout << ans;
	return 0;
}