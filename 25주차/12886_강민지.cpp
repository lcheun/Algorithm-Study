// 골드4
// Created by KangMinji on 2023-05-24.
// https://www.acmicpc.net/problem/12886

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[1501][1501];

void bfs(int a, int b, int c){
	queue<pair<int, int>> q;

	// 초기값
	q.push({a, b});
	visited[a][b] = true;

	int sum = a + b + c;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int num[3] = {x, y, sum - x - y};

		for (int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				if (num[i] < num[j]){
					int nx = num[i] * 2;
					int ny = num[j] - num[i];
					if (visited[nx][ny]){
						continue;
					}
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main() {
	int a, b, c;

	// 입력
	cin >> a >> b >> c;

	// 연산
	int sum = a + b + c;
	if (sum % 3 != 0){
		cout << "0\n";
		return 0;
	}

	bfs(a, b, c);

	// 출력
	cout << visited[sum/3][sum/3];
}