#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    bool deleted[1000000] = {false, };
    for(int i=0; i<T; i++){
        int k;
        cin >> k;
        
        priority_queue<pair<int, int>> maxQ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
        
        char cmd; int n;
        for(int i=0; i<k; i++){
            cin >> cmd >> n;
            if(cmd == 'I'){
                maxQ.push({n, k});
                minQ.push({n, k});
            }
            else if(cmd == 'D'){
                if(n == -1) {
                    while(!deleted[minQ.top().second]) minQ.pop();
                    deleted[minQ.top().second] = true;
                    minQ.pop();
                }
                else {
                    while(!deleted[maxQ.top().second]) maxQ.pop();
                    deleted[maxQ.top().second] = true;
                    maxQ.pop();
                }
            }
        }
        memset(deleted, false, sizeof(bool)*k);
    }
}
