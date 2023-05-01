//
// Created by KangMinji on 2023-04-28.
// https://school.programmers.co.kr/learn/courses/30/lessons/92343

#include <vector>
#include <set>
using namespace std;

int answer = -1;
vector<vector<int>> graph; // {값, left idx, right idx};

//    단순한 backtracking이 아님!
//   1을 선택한 상태로 8을 갈 수 있어야 함 -> 갈 수 있는 노드 목록을 저장해야 함
// adj_list를 공유하면 안 되고 각 분기마다 따로따로 해줘야 함
void backtracking(int node, int sheep, int wolf,
set<int> adj_list, vector<int> &info){

    info[node] ? wolf++ : sheep++;
    if (sheep <= wolf){ // 종료 조건
        return;
    }
    // 방문 확정
    answer = max(answer, sheep);
    adj_list.erase(node);

    // 해당 노드의 인접 노드 추가
    for (int adj : graph[node]){
        adj_list.insert(adj);
    }

    // 인접 노드 방문
    for (auto next : adj_list){
        backtracking(next, sheep, wolf, adj_list, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    graph.assign(17, vector<int>());
    for (int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    set<int> adj_list;
    backtracking(0, 0, 0, {adj_list}, info);
    return answer;
}