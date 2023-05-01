//
// Created by KangMinji on 2023-04-29.
// https://school.programmers.co.kr/learn/courses/30/lessons/160585

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool checkComplete(char shape, vector<string> &board){
	// 행, 열 체크
	for (int i=0; i<3; i++){
		// board[i][0] == board[i][1] == board[i][2] == shape 안 먹힘!!
		if (board[i][0] == shape && board[i][1] == shape && board[i][2] == shape){
			return true;
		}
		if (board[0][i] == shape && board[1][i] == shape && board[2][i] == shape){
			return true;
		}
	}

	// 대각선 체크
	if (board[0][0] == shape && board[1][1] == shape && board[2][2] == shape)
		return true;
	if (board[0][2] == shape && board[1][1] == shape && board[2][0] == shape)
		return true;
	return false;
}

/*
[불가능한 경우]
1) [둘 다 완성] o랑 x가 동시에 완성될 수 없음
2) [둘 다 미완성] #x > #o 이거나 #o > #x + 1일 수 없음
3) [하나만 완성]
3-1) o가 완성되었는데 #x != #o -1
3-2) x가 완성되었는데 #x != #o 인 경우
*/
bool checkValid(vector<string> &board, int o_cnt, int x_cnt){
	bool o_complete = checkComplete('O', board);
	bool x_complete = checkComplete('X', board);

	cout << o_complete << " " << x_complete << '\n';
	// 1) 둘 다 동시에 완성된 경우
	if (o_complete && x_complete){
		cout << "1번";
		return false;
	}
	// 2) 둘 다 완성되지 못한 경우
	if (!o_complete && !x_complete && (x_cnt > o_cnt || o_cnt > x_cnt + 1)){
		cout << "2번";
		return false;
	}
	// 3) 하나만 완성된 경우
	if (o_complete && (x_cnt != o_cnt - 1)){
		cout << "3-1번";
		return false;
	}
	if (x_complete && (x_cnt != o_cnt)){
		cout << "3-2번";
		return false;
	}
	return true;
}

int solution(vector<string> board) {
	int o_cnt = 0, x_cnt = 0;

	for (string s : board){
		for (char c : s){
			if (c == '.'){
				continue;
			}
			c == 'O' ? o_cnt++ : x_cnt++;
		}
	}

	int answer = checkValid(board, o_cnt, x_cnt) ? 1 : 0;
	return answer;
}