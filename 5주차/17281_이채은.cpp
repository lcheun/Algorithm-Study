#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int N, score, ans;
int result[50][9];
bool is_selected[9], is_ground_on[3];
vector<int> player_seq;

void move(int n) {
    for(int i=2; i>=0; i--) {
        if(is_ground_on[i]) {
            if(i+n >= 3) score++;
            else is_ground_on[i + n] = true;
            is_ground_on[i] = false;
        }
    }
    if(n == 4) score++;
    else is_ground_on[n-1] = true;
}

void play() {
    int out_cnt, idx = 0;
    score = 0;
    
    for(int i=0; i<N; i++) {
        out_cnt = 0;
        memset(is_ground_on, false, sizeof(is_ground_on));

        while(true) {
            if(idx >= 9) idx = 0;

            if(result[i][player_seq[idx]] == 0) {
                if(++out_cnt == 3) {
                    idx++;
                }
            }
            else move(result[i][player_seq[idx]]);
            idx++;
        }
    }
    
    ans = max(ans, score);
}

void select() {
    if(player_seq.size() == 8) {
        player_seq.insert(player_seq.begin()+3, 0);
        play();
        player_seq.erase(player_seq.begin()+3);
        
        return;
    }
    
    for(int i=1; i<9; i++) {
        if(!is_selected[i]) {
            is_selected[i] = true;
            player_seq.push_back(i);
            select();
            player_seq.pop_back();
            is_selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<9; j++){
            cin >> result[i][j];
        }
    }
    
    select();
    cout << ans;
}
