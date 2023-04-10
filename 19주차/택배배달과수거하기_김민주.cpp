#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deli = 0; // 남은 배달할 양
    int pick = 0; // 남은 픽업할 양
    
    
    // 뒤에서부터 본다 -> 한번에 최대한 멀리 가서 멀리 있는 곳들의 작업을 먼저 끝내야 이동횟수를 최소한으로 만들 수 있다.
    for(int i=n-1;i>=0;i--){
        deli += deliveries[i];
        pick += pickups[i];
        
        // deli와 pick 이 모두 음수면 해당 위치의 배달/픽업 값이 한번에 실어나를 수 있는 용량 (=cap) 보다 작은 것이기 때문에 오가는 길에 겸사겸사 추가적으로 배달/픽업이 가능하다.
        while(deli>0 || pick >0) {
            deli -= cap;
            pick -= cap;
            
            answer += (i+1)*2; // 어차피 가면 다시 물류창고로 되돌아와야 하므로 *2
        }
    }
    
    return answer;
}
