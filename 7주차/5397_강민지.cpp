//
// Created by KangMinji on 2023-01-13.
//

#include <iostream>
#include <stack>

using namespace std;

string findPwd(string str) {
    stack<char> left;
    stack<char> right;

    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '-':
                if (!left.empty()){
                    left.pop();
                }
                break;
            case '<':
                if (!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
                break;
            case '>':
                if (!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
                break;
            default:
                left.push(str[i]);
        }
    }

    // SOOB : SB<O<O
    // [SO] [BO] 식으로 되어 있기 때문에 left, right 각각 reverse하거나
    // left를 right로 옮기고 그 다음 right를 reverse해야 함
    string result = "";
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        result += right.top();
        right.pop();
    }
    return result;
}

int main() {
    int T;
    string str;

    // 입력
    cin >> T;
    while (T--) {
        cin >> str;
        cout << findPwd(str) << "\n";
    }
}