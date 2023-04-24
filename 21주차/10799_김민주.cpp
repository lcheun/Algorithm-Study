#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> st;
    
    string input;
    cin >> input;
    
    int answer = 1;
    
    char before = '(';
    st.push(before);
    for(int i=1;i<input.size();i++) {
        char c = input[i];
        //레이저
        if(before=='('&&c==')') {
            st.pop();
            answer -= 1;
            answer += st.size();
        }
        else if(c=='('){
            st.push('(');
            answer += 1;
        } else {
            st.pop();
        }
        before = c;
    }
    
    cout << answer;
}
