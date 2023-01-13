//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 2* 1e5; // (n-1)*(간선 가중치)

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table){
    for (int k=1; k<=n; k++){ // 중간 노드
        for (int i=1; i<=n; i++){ // 시작 노드
            for (int j=1; j<=n; j++){ // 종료 노드
                int cost = graph[i][k] + graph[k][j];
                if (cost < graph[i][j]){
                    graph[i][j] = cost;
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

/*
 * 최소 비용을 저장하는 graph
 * 집하장 번호를 저장하는 경로표 table
 */
int main() {
    int n, m, a, b, c;

    // 입력
    cin >> n >> m;
    // 집하장 번호 1부터 시작
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    while(m--){
        cin >> a >> b >> c;

        // 비용 정보 저장
        graph[a][b] = graph[b][a] = c;

        // 집하장 정보 저장
        table[a][b] = b;
        table[b][a] = a;
    }

    // 연산
    floydWarshall(n, graph, table);

    // 출력
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j) {
                cout << "- ";
            } else {
                cout << table[i][j] << " ";
            }
        }
        cout << "\n";
    }
}