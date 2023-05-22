// 골드5
// Created by KangMinji on 2023-05-22.
// https://www.acmicpc.net/problem/2023

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> ans;

bool isPrime(int num){
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

void backtracking(int now,int depth,int n){
	if(isPrime(now)){
		if(depth == n){
			ans.push_back(now);
			return;
		}
		for(int i = 1; i < 10; i++){
			backtracking(now*10 + i, depth+1, n);
		}
	}
}

int main(){
	int n;
	cin >> n;

	// 기본적으로 시작이 소수여야 함 : 2, 3, 5, 7
	backtracking(2, 1, n);
	backtracking(3, 1, n);
	backtracking(5, 1, n);
	backtracking(7, 1, n);

	for(int i  =0; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
}