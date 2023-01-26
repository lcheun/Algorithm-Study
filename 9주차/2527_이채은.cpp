#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int square1[4], square2[4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) cin >> square1[j];
        for(int j=0; j<4; j++) cin >> square2[j];
        
        int x = max(square1[0], square2[0]);
        int y = max(square1[1], square2[1]);
        int p = min(square1[2], square2[2]);
        int q = min(square1[3], square2[3]);
        
        int xdiff = p - x, ydiff = q - y;
        
        if (xdiff > 0 && ydiff > 0) cout << 'a' << '\n';
        else if (xdiff < 0  || ydiff < 0) cout << 'd' << '\n';
        else if (xdiff == 0 && ydiff == 0) cout << 'c' << '\n';
        else cout << 'b' << '\n';
    
    }
    
}
