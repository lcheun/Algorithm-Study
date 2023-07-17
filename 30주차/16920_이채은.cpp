#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 1000
#define P_MAX 10
using namespace std;
 
int N, M, P;
int Move_Area[10];
int Count_Area[10];
bool Visit[1000][1000];
bool Flag[10];
char MAP[1000][1000];
queue<pair<pair<int, int>, int>> Q[10];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
bool bfs(int Idx) {
	bool Temp_Flag = false;
	queue<pair<pair<int, int>, int>> NQ = Q[Idx];
	while (NQ.empty() == 0) {
		int x = NQ.front().first.first;
		int y = NQ.front().first.second;
		int Cnt = NQ.front().second;
		NQ.pop();
 
		if (Cnt == Move_Area[Idx]) Q[Idx].pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCnt = Cnt;
 
			if (nCnt == 0) break;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (MAP[nx][ny] == '.')
				{
					MAP[nx][ny] = Idx + '0';
					Count_Area[Idx]++;
					Q[Idx].push({{nx, ny}, Move_Area[Idx]});
					NQ.push(make_pair(make_pair(nx, ny), nCnt - 1));
					Temp_Flag = true;
				}
			}
		}
	}
	return Temp_Flag;
}
 
bool Check()
{
	for (int i = 1; i <= P; i++)
	{
		if (Flag[i] == true) return true;
	}
	return false;
}
 
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> Move_Area[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if ('1' <= MAP[i][j] && MAP[i][j] <= '9')
			{
				Q[MAP[i][j] - '0'].push(make_pair(make_pair(i, j), Move_Area[MAP[i][j] - '0']));
				Count_Area[MAP[i][j] - '0']++;
			}	
		}
	}
	memset(Flag, true, sizeof(Flag));
  
	while (true) {
		for (int i = 1; i <= P; i++)
		{
			if (Flag[i] == false) continue;
			bool Temp_Flag = bfs(i);
			if (Temp_Flag == false) Flag[i] = false;
		}
 
		if (Check() == false) break;
	}
 
	for (int i = 1; i <= P; i++) {
		cout << Count_Area[i] << " ";
	}
	cout << '\n';
}
