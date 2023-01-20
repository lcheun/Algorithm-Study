#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
vector<int> W;

void backtracking(int val){
    
    int s = (int) W.size();
    
    if(s == 2){
        ans = max(ans, val);
        return;
    }
    
    for(int i=1; i<s-1; i++){
        int e = W[i], new_val = val + W[i-1] * W[i+1];
        W.erase(W.begin()+i);
        backtracking(new_val);
        W.insert(W.begin()+i, e);
    }
    
}

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int e;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> e;
        W.push_back(e);
    }
    
    backtracking(0);
    cout << ans;
}
