// https://www.acmicpc.net/problem/10799
// Created by KangMinji on 2023-04-24.
// 실버2

#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
// 완전히 포함되되, 끝점은 겹치지 않도록
// 쇠막대기에 포함되는 레이저 적어도 1개
// 양 끝점과 레이저는 겹치지 않음

int calcPiece() {
	int answer = 0;
	int cnt = 0; // ) 숫자

	while(!st.empty()){
		char c = st.top();
		st.pop();
		if (c == ')'){
			cnt++;
		} else if (c == '('){
			answer++;
			cnt--;
		} else { // 레이저 만났을 때 : ) 개수만큼 더해준다
			answer += cnt;
		}
	}
	return answer;
}

int main() {
	// 시간 초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	for (char c : str){
		if (c == ')'){
			// 레이저 표시
			if (!str.empty() && st.top() == '('){
				st.pop();
				st.push('*');
				continue;
			}
		}
		st.push(c);
	}

	// 연산 & 출력
	cout << calcPiece();
}