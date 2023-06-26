#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int DP[61][61][61];
int HP[3];

int solution(int x, int y, int z) {
	if (x < 0)return solution(0, y, z);
	if (y < 0)return solution(x, 0, z);
	if (z < 0)return solution(x, y, 0);

	if (x == 0 && y == 0 && z == 0)return 0;

	int res = DP[x][y][z];

	if (res != -1) return res;

	res = 1000000000;
  
	res = min(res, solution(x - 9, y - 3, z - 1) + 1);
	res = min(res, solution(x - 9, y - 1, z - 3) + 1);
	res = min(res, solution(x - 3, y - 9, z - 1) + 1);
	res = min(res, solution(x - 1, y - 9, z - 3) + 1);
	res = min(res, solution(x - 3, y - 1, z - 9) + 1);
	res = min(res, solution(x - 1, y - 3, z - 9) + 1);

	return res;
}

int main() {
	cin >> N;

	memset(DP, -1, sizeof(DP));

	for (int i = 0; i < N; i++) {
		cin >> HP[i];
	}
	cout << solution(HP[0], HP[1], HP[2]) << '\n';
}
