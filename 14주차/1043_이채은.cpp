#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
int parents[51];
vector<int> truth;
vector<vector<int> > v(50);
 
 
int Find(int x) {
    if(parents[x] == x) return x;
    return x = Find(parents[x]);
}
 
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    int p;
    while(K--) {
        cin >> p;
        truth.push_back(p);
    }
    
    for(int i=1; i<=N; i++) parents[i] = i;
    for(int i=0; i<M; i++){
        cin >> p;
        int num, prev;
        for(int j=0; j<p; j++){
            if(j >= 1){
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else cin >> num;
            v[i].push_back(num);
        }
    }
    
    for(auto list : v){
        bool flag = false;
        for(auto person : list){
            if(flag) break;
            for(auto t : truth){
                if(Find(person) == Find(t)){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) M--;
    }
    
    cout << M;
}
