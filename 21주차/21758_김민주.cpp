#include <iostream>
#include <stack>

#define MAX 100001

using namespace std;

int honey[MAX];
int sum[MAX];

int main() {
    int N; cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> honey[i];
        sum[i] = sum[i-1]+honey[i];
    }
    
    int answer = 0;
    
    //벌꿀벌 -> 벌들이 양 끝에서 시작
    // i는 꿀위치
    for(int i=2;i<N;i++){
        answer = max(answer, sum[i]-sum[1] + sum[N-1]-sum[i-1]);
    }
    //벌벌꿀 -> 한마리는 최대한 왼쪽에서 시작, 꿀은 오른쪽
    // i는 벌위치
    for(int i=2;i<N;i++) {
        answer = max(answer, sum[N]-sum[1]-honey[i] + sum[N]-sum[i]);
    }
    //꿀벌벌 -> 꿀 최대한 왼쪽, 한마리 벌은 오른쪽
    //i는 벌위치
    for(int i=2;i<N;i++){
        answer = max(answer, sum[N-1]-sum[0]-honey[i] + sum[i-1]-sum[0]);
    }
    
    cout << answer;
}
