#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N1, N2, t;
    string str1, str2;
    vector<pair<char, int>> v;
    
    cin >> N1 >> N2 >> str1 >> str2 >> t;
    for(int i=N1-1; i>=0; i--) v.push_back({str1[i], 0});
    for(int i=0; i<N2; i++) v.push_back({str2[i], 1});
    
    int time = 0;
    while(time != t) {
        for(int i=0; i<N1+N2-1; i++){
            if(v[i].second == 0 && v[i+1].second == 1){
                swap(v[i], v[i+1]);
                i++;
            }
        }
        time++;
    }
    
    for(int i=0; i<N1+N2; i++)
        cout << v[i].first;
}
