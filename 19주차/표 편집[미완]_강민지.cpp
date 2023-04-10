//
// Created by KangMinji on 2023-04-10.
//

#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int n;
	Node* prev;
	Node* next;
	Node(int n) : n(n), prev(NULL), next(NULL) {}
};

void editTable(vector<Node*> &table, stack<Node*> &removed, vector<string> &cmd, Node* cur){
	int num = 0;
	for (string str : cmd){
		switch(str[0]){
			case 'U':
				num = stoi(str.substr(2));
				while(num--){
					cur = cur->prev;
				}
				break;
			case 'D':
				num = stoi(str.substr(2));
				while(num--){
					cur = cur->next;
				}
				break;
			case 'C':
				removed.push(cur);
				// 바로 아래 행을 선택
				if (cur->prev == NULL) { // 첫번째
					cur->next->prev = NULL;
					cur = cur->next;
				} else if (cur->next == NULL){ // 마지막
					cur->prev->next = NULL;
					cur = cur->prev;
				} else {
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					cur = cur->next;
				}
				break;
			case 'Z':
				Node* top = removed.top();
				removed.pop();

				if (top->prev != NULL){
					top->prev->next = top;
				}
				if (top->next != NULL){
					top->next->prev = top;
				}
				break;
		}
	}
}

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');

	vector<Node*> table;
	stack<Node*> removed;

	for (int i=1; i<=n; i++){
		table.push_back(new Node(i));
	}

	table[0]->next = table[1];
	table[n-1]->prev = table[n-2];
	for (int i=1; i<n-1; i++){
		table[i]->next = table[i+1];
		table[i]->prev = table[i-1];
	}

	// k로 커서 이동
	Node* cur = table[k];

	// 연산
	editTable(table, removed, cmd, cur);

	// 출력
	while(cur->prev != NULL){
		cur = cur->prev;
	}

	while(cur != NULL){
		answer[cur->n] = 'O';
		cur = cur->next;
	}
	return answer;
}