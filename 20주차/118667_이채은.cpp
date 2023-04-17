#include <string>
#include <vector>
#include <numeric>

using namespace std;

int q_size;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    q_size = queue1.size();
    int answer = 0;
    
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    int p1_first = 0, p1_end = q_size-1;
    int p2_first = q_size, p2_end = 2*q_size - 1;
    
    while(answer <= 4*q_size) {
        if(sum1 > sum2) {
            sum1 -= queue1[p1_first];
            sum2 += queue1[p1_first];
            
            p1_first = (p1_first + 1 >= 2*q_size) ? 0 : p1_first + 1;
            p2_end = (p2_end + 1 >= 2*q_size) ? 0 : p2_end + 1;
        } else if(sum1 < sum2) {
            sum2 -= queue1[p2_first];
            sum1 += queue1[p2_first];
            
            p2_first = (p2_first + 1 >= 2*q_size) ? 0 : p2_first + 1;
            p1_end = (p1_end + 1 >= 2*q_size) ? 0 : p1_end + 1;
        } else return answer;
        
        answer++;
    }
    
    return -1;
}
