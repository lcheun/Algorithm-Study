//
// Created by KangMinji on 2023-03-20.
//
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
const int MAX = 1e5 + 1;

// https://hwan-shell.tistory.com/263 참고
vector<int> solution(vector<string> gems) {
	vector<int> answer(2, 0);
	map<string, int> m;

	// 보석 종류 확인
	for (string gem : gems){
		m[gem] = 0;
	}
	int gemCnt = m.size();
	m.clear();

	int len = MAX;
	int start = 0, end = 0;
	while(true){
		// 보석 다 모은 경우
		if (m.size() == gemCnt){
			// 1) length가 최소인지 확인 -> 최소라면 answer에 반영
			if (end - start < len){
				answer[0] = start + 1;
				answer[1] = end;
				len = end - start;
			}
			// 2) start pointer 증가(구간 길이 감소)
			if (m[gems[start]] == 1){
				m.erase(gems[start]);
			}
				// 3) 뒷 부분도 탐색
			else {
				m[gems[start]]--;
				cnt--;
			}
			start++;
		}

			// 종료조건
		else if (end == gems.size()){
			break;
		}

			// 보석 아직 못 모은 경우 : end pointer 증가시키며 찾는다
		else {
			m[gems[end]]++;
			end++;
		}
	}

	return answer;
}