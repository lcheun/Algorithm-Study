#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N; cin >> N;
    
  //스택 써서 같은 글자 만나면 pop해줌
  //아니면 push
  // 모두 진행됐을 때 st이 비어있다면 좋은 단어
    int answer = 0;
    while(N--) {
        string input; cin >> input;
        stack<char> st;
        
        for(int i=0;i<input.size();i++){
            char c = input[i];
            
            if(!st.empty()) {
                if(st.top()==c){
                    st.pop();
                } else{
                    st.push(c);
                }
            } else{
                st.push(c);
            }
        }
        if(st.empty()) answer++;
    }
    
    cout << answer;
}
