#include <iostream>
#include <algorithm>

using namespace std;

string S, T;

int dfs(string tmp){
    if(tmp == S) return 1;
    if(S.size() > tmp.size()) return 0;

    int ans = 0;

    if(tmp[tmp.size() - 1] == 'A'){
        tmp.pop_back();
        ans = max(ans,dfs(tmp));
        tmp.push_back('A');
    }
    if(tmp[0] == 'B'){
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        ans = max(ans, dfs(tmp));
    }
    
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> T;
    cout << dfs(T);
    
}

