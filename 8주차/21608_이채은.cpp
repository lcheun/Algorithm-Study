#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, student[400], visited[20][20];
bool like[400][400];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool cmp(pair<pair<int,int>,pair<int,int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
    if (a.first.first == b.first.first) {
        if (a.first.second == b.first.second) {
            if (a.second.first == b.second.first) {
                return a.second.second < b.second.second;
            }
            return a.second.first < b.second.first;
        }
        return a.first.second > b.first.second;
    }
    return a.first.first > b.first.first;
}

int count() {
    int result = 0;
    int score[5] = { 0, 1, 10, 100, 1000 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int like_cnt = 0;
            int num = visited[i][j];
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && nx < n && ny >= 0 && nx < n && like[num][visited[ny][nx]] != 0){
                    like_cnt++;
                }
            }
            result += score[like_cnt];
        }
    }
    return result;
}

void solve(int idx) {
    int num = student[idx];
    vector<pair<pair<int, int>, pair<int, int>>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            int like_num = 0;
            int empty = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && nx < n && ny >= 0 && nx < n) {
                    if(like[num][visited[ny][nx]] != 0) like_num++;
                    else if(!visited[ny][nx]) empty++;
                }
            }
            pos.push_back({{like_num, empty}, {i,j}});
        }
    }
    
    sort(pos.begin(), pos.end(), cmp);

    visited[pos[0].second.first][pos[0].second.second] = num;

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n*n; i++) {
        cin >> student[i];
        for (int j = 1; j < 5; j++) {
            int tmp;
            cin >> tmp;
            like[student[i]][tmp] = true;
        }
    }
    
    for(int i = 0; i < n*n; i++) {
        solve(i);
    }
    
    cout << count();
}
