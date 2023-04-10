#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
    long long answer = 0;
    int box = 0;
    stack<int> deliver, pick;

    for (auto i : deliveries) deliver.push(i);
    for (auto i : pickups) pick.push(i);

    while (!deliver.empty() && deliver.top() == 0) deliver.pop();
    while (!P.empty() && P.top() == 0) pick.pop();


    while (!(deliver.empty() && pick.empty())) {
        answer += max(deliver.size() * 2, pick.size() * 2);

        box = 0;
        while (!deliver.empty() && box <= cap) {
            if (deliver.top() + box <= cap) box += deliver.top();
            else {
                deliver.top() -= (cap - box); break;
            }
            deliver.pop();
        }

        box = 0;
        while (!pick.empty() && box <= cap) {
            if (pick.top() + box <= cap) 
                box += pick.top();
            else {
                pick.top() -= (cap - box); break;
            }
            pick.pop();
        }
    }
    
    return answer;
}
