//
// Created by KangMinji on 2023-04-10.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int SIZE = 5;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool checkAvail(int x, int y, vector<string> &place){
	int person_cnt = 0;

	for (int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE){
			continue;
		}
		if (place[nx][ny] == 'P'){
			person_cnt++;
		}
	}

	if ((place[x][y] == 'P' && person_cnt >= 1)
		|| (place[x][y] == 'O' && person_cnt >= 2)){
		return false;
	}
	return true;
}

bool checkDist(vector<string> &place){
	bool flag;
	// 빈 테이블 -> 사람 2명 이상이면 out
	// 사람 -> 사람 1명 이상이면 out
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			if (place[i][j] == 'X'){
				continue;
			}
			if (!checkAvail(i, j, place)){
				// break문을 쓰면 전체 for문 탈출 X 그냥 return으로 해야 함
				return false;
			}
		}
	}
	return true;
}

// 맨해튼 거리 2 이하는 x  |r1 - r2| + |c1 - c2|
// 단, 맨해튼 거리 2이고, 파티션으로 막혀있는 경우는 ok
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i=0; i<SIZE; i++){
		answer.push_back(checkDist(places[i]));
	}
	return answer;
}