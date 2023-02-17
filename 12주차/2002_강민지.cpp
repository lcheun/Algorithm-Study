// 실버1
// Created by KangMinji on 2023-02-17.
// https://www.acmicpc.net/problem/2002

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	string input;
	map<string, int> m;

	// 입력 : 복잡하니까 숫자로 바꿔서 표현
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> input;
		m[input] = i;
	}

	vector<int> seq;
	for (int i=0; i<n; i++){
		cin >> input;
		seq.push_back(m[input]);
	}

	// 연산
	int answer = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (seq[i] > seq[j]){
				answer++;
				break;
			}
		}
	}

	// 출력
	cout << answer << "\n";
}