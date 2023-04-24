#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        string word;
        cin >> word;
        
        stack<char> stk;
        for(char c : word){
            if(!stk.empty() && c == stk.top()){
                stk.pop();
            }
            else stk.push(c);
        }
        
        if(stk.empty()) ans++;
    }
    
    cout << ans;

}
