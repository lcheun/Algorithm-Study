// 실버3
// Created by KangMinji on 2023-08-14.
// https://www.acmicpc.net/problem/20920

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
vector<string> word;
map<string, int> wordmap;

bool cmp(const string &a, const string &b) {
	if (wordmap[a] != wordmap[b])
		return wordmap[a] > wordmap[b];
	if (a.length() != b.length())
		return a.length() > b.length();
	return a < b;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;
	string input;
	for (int i=0; i<n; i++){
		cin >> input;
		if (input.length() < m) continue;

		if (wordmap.find(input) == wordmap.end()){
			word.push_back(input);
		}
		wordmap[input]++;
	}

	// 연산
	sort(word.begin(), word.end(), cmp);

	// 출력
	for (string w : word)
		cout << w << '\n';
}