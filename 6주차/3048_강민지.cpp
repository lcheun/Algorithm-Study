//
// Created by KangMinji on 2023-01-06.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<char, int> ci; // {알파벳, 방향} : 방향 1(오른쪽) / 0(왼쪽)

/*
 * 앞, 뒤 개미의 방향이 서로 반대인 경우 둘이 swap
 */
int main() {
    int n1, n2, t;
    string s;

    // 입력
    cin >> n1 >> n2;
    vector<ci> ant_list;
    cin >> s;
    for (int i = n1 - 1; i >= 0; i--) {
        ant_list.push_back({s[i], 1});
    }
    cin >> s;
    for (int i = 0; i < n2; i++) {
        ant_list.push_back({s[i], 0});
    }
    cin >> t;

    // 연산
    while(t--){
        for (int i=0; i<n1+n2-1; i++){
            // -> <- 인 경우!
            // 불일치로만 가면 <- ->도 해당되기 때문에 하나씩 지정해줘야 함
            if (ant_list[i].second == 1 && ant_list[i+1].second == 0){
                swap(ant_list[i], ant_list[i+1]);
                i++; // 🔥🔥🔥 이거 없으면 계속 바꾼다
            }
        }
    }

    // 출력
    for (auto ant : ant_list){
        cout << ant.first;
    }
}
