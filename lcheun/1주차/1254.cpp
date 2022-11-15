#include <iostream>
#include <string>

using namespace std;

string S;
int len;

bool isPalindrome(int idx) {
    int mid = (len-idx) / 2;
    for(int i=0; i<mid; i++)
        if(S[idx+i] != S[len-1-i])
            return false;
    return true;
}

int main(){
    cin >> S;
    len = S.size();
    
    for(int i=0; i<len; i++){
        if(isPalindrome(i)){
            cout << len + i << '\n';
            break;
        }
    }
}
