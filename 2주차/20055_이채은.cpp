#include <stdio.h>
#include <stdbool.h>

int N, K, cnt = 0, zero = 0;
int belt[200];
bool robot[100] = { false, };

void simul() {
    int pre, val = belt[0];
    bool preb, valb = robot[0];
    cnt++; //단계
    for (int i = 0; i < 2 * N; i++) {
        pre = belt[(i + 1) % (2 * N)];
        belt[(i + 1) % (2 * N)] = val;
        val = pre;
    }
    for (int i = N - 2; i >= 0; i--) {
        if (robot[i]) {
            robot[i + 1] = true;
            robot[i] = false;
        }
    }
    if (robot[N - 1]) robot[N - 1] = false; //1번
    for (int i = N - 2; i >= 0; i--) {
        if (robot[i] && !robot[i + 1] && belt[i + 1] > 0) {
            robot[i] = false;
            robot[i + 1] = true;
            if (--belt[i + 1] == 0) {
                zero++;
            }
        }
    }
    if (robot[N - 1]) robot[N - 1] = false; //2번
    if (!robot[0] && belt[0] != 0) {
        if (--belt[0] == 0) zero++;
        robot[0] = true;
   
    } //3번
    if (zero < K) simul();//4번
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < 2 * N; i++)
        scanf("%d", &belt[i]);
    simul();
    printf("%d", cnt);
}
