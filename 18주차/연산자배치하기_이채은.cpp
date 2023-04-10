#include <iostream>
#include <algorithm>

using namespace std;

int n, min_val = 1000000000, max_val = -1000000000;
int num[12], operation[3]; //덧셈 뺄셈 곱셈

void calc(int cnt, int val){
    if(cnt == n-1){
        min_val = min(val, min_val);
        max_val = max(val, max_val);
        return;
    }

    for(int i=0; i<3; i++){
        int n_val = val;
        if(operation[i] <= 0) continue;
        if(i == 0) n_val += num[cnt+1];
        if(i == 1) n_val -= num[cnt+1];
        if(i == 2) n_val *= num[cnt+1];
        operation[i]--;
        calc(cnt+1, n_val);
        operation[i]++;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];
    for(int i=0; i<3; i++) cin >> operation[i];

    calc(0, num[0]);
    cout << min_val << ' ' << max_val;

    return 0;
}
