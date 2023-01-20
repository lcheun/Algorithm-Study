#include <iostream>
#include <algorithm>

using namespace std;

int N, M, B, ans_time = 2147483647, ans_h;
int h[501][501];

int calc(int val){
    int r_block = 0, a_block = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(h[i][j] > val) r_block += h[i][j] - val;
            else if(h[i][j] < val) a_block += val - h[i][j];
        }
    }
    
    if (a_block > r_block + B) return 2147483647;
    return a_block + r_block * 2;
}

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int min_h = 257, max_h = 0;
    cin >> N >> M >> B;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> h[i][j];
            min_h = min(h[i][j], min_h);
            max_h = max(h[i][j], max_h);
        }
    }
    
    for(int i=0; i<=256; i++){
        int val = calc(i);
        if(val <= ans_time){
            ans_time = val;
            ans_h = i;
        }
    }
    
    cout << ans_time << ' ' << ans_h;
}
