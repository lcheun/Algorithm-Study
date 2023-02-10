#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sum = 0;
    string s;
    vector<int> v;
    
    cin >> s;
    for(char c:s){
        sum += c-'0';
        v.push_back(c-'0');
    }
    
    if(sum % 3 == 0){
        sort(v.begin(), v.end(), greater<int>());
        if(v.back() == 0){
            for(int i:v) cout << i;
            exit(0);
        }
    }
    cout << -1;
}
