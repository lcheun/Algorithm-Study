#include <iostream>
#include <vector>

using namespace std;
 
int N;
int map[101][101];
vector<char> v;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

 
int change_direction(int dir, char cmd) {
    if(cmd == 'R') {
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 1;
        else if(dir == 3) return 0;
    }
    else if(cmd == 'L') {
        if(dir == 0) return 3;
        else if(dir == 1) return 2;
        else if(dir == 2) return 0;
        else if(dir == 3) return 1;
    }
    
    return -1;
}
 
void simul() {
    int x = 50, y = 50, dir = 2;
    map[x][y] = 1;
 
    for(int i = 0; i < N; i++) {
        if(v[i] == 'R' || v[i] == 'L') dir = change_direction(dir, v[i]);
        else if(v[i] == 'F') {
            x = x + dx[dir];
            y = y + dy[dir];
            map[x][y] = 1;
        }
    }
 
    int sx, sy, ex, ey;
    sx = sy = 101;
    ex = ey = 0;
 
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(map[i][j] == 1) {
                if(i < sx) sx = i;
                if(j < sy) sy = j;
                if(i > ex) ex = i;
                if(j > ey) ey = j;
            }
        }
    }
 
    for(int i=sx; i<=ex; i++) {
        for(int j=sy; j<=ey; j++) {
            if(map[i][j] == 1) cout << ".";
            else cout << "#";
        }
        cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        char a;
        cin >> a;
        v.push_back(a);
    }
    
    simul();
}
