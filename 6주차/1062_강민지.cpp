//
// Created by KangMinji on 2023-01-05.
//

#include <iostream>
#include <vector>
using namespace std;

int n, k, ans = 0;
vector<string> word_list;
bool alphabet[26] = {false, };

/*
 * 0) 기본적으로 a, n, t, i, c는 읽을 줄 알아야 한다 - k-5 > 0 이상이어야 함
 * 1) 문자열에서 anta, tica 제거
 * 2) 남은 알파벳에서 3개씩 추출
 * 3) 해당 조합으로 읽을 수 있는 단어의 개수 count
 */
void dfs(int idx, int word_cnt){
    // 알파벳을 k개 고른 경우
    if (word_cnt == k) {
        int cnt = 0;
        // 해당 단어의 조합으로 읽을 수 있는 단어의 개수 count
        for (string word : word_list){
            bool canRead = true;
            for (char c : word) {
                if (!alphabet[c - 'a']) {
                    canRead = false;
                    break;
                }
            }
            if (canRead){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    // 알파벳 3개 선택(백트래킹)
    for (int i=idx; i<26; i++){
        if (alphabet[i]){
            continue;
        }
        alphabet[i] = true;
        dfs(i, word_cnt+1);
        alphabet[i] = false;
    }
}

int main() {
    string s;

    // 입력
    cin >> n >> k;

    // 종료조건 확인
    if (k < 5) {
        cout << "0\n";
        return 0;
    } else if (k == 26) {
        cout << n << "\n";
        return 0;
    }

    k -= 5;
    alphabet['a' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;

    while (n--) {
        // 1) 문자열에서 anta, tica 제거
        cin >> s;
        s.substr(4, s.size() - 8);
        word_list.push_back(s);
    }

    // 연산
    dfs(0, 0);

    // 출력
    cout << ans << "\n";
}