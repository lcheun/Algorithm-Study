#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
    
    int D, N, num, pizza;
    vector<int> v;
    
    cin >> D >> N;
    cin >> num;
    v.push_back(num);
    
    for (int i=1; i<D; i++){
        cin >> num;
        v.push_back(min(num, v[i-1]));
    }
    
    int ans = D-1;
    for(int i=0; i<N; i++) {
        cin >> pizza;
        if(ans<0 || pizza>v[0]) {
            cout << 0;
            exit(0);
        }
        
        for (int j=ans; j>=0; j--) {
            if(v[j] >= pizza) {
                ans = j-1;
                break;
            }
        }
    }
    
    cout << ans + 2 << '\n';
}
