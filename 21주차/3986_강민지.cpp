// https://www.acmicpc.net/problem/3986
// Created by KangMinji on 2023-04-24.
// 실버4

#include <iostream>
#include <stack>
using namespace std;

// AAAA 좋은 단어 아닌 줄 알았는데 돼서 놀람.....?
// 각 글자를 "정확히 한 개의" 다른 위치에 있는 같은 글자와 짝 지을 수 있어야 함
// 2개 뭉텅이가 2번 이상 연속
bool check(string input) {
	stack<char> st;

	for (char c : input){
		if (st.empty()){
			st.push(c);
			continue;
		}

		if (st.top() == c){
			st.pop();
		} else {
			st.push(c);
		}
	}

	if (st.empty()){
		return true;
	}
	return false;
}

int main() {
	int n, answer = 0;
	string input;

	// 입력 & 연산
	cin >> n;
	while (n--) {
		cin >> input;
		if (check(input)) {
			answer++;
		}
	}

	// 출력
	cout << answer << '\n';
}
