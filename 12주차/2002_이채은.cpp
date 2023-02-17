#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int N, arr[1001];
    
    cin >> N;
    
    map<string, int> m;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        m[str] = i;
    }
    
    int num = 0;
    for(int i=0; i<N; i++){
        cin >> str;
        arr[i] = m[str];
    }
    
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(arr[i] > arr[j]){
                num++; break;
            }
        }
    }
    
    cout << num;
}
