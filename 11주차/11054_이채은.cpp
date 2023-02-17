#include <stdio.h>

int N, ans = 0;
int arr[1000], inc[1000] = { 0, }, dec[1000] = { 0, };

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && tmp < inc[j])
                tmp = inc[j];
        }
        inc[i] = tmp + 1;
    }

    for (int i = N - 1; i >= 0; i--) {
        int tmp = 0;
        for (int j = N - 1; j > i; j--) {
            if (arr[i] > arr[j] && tmp < dec[j])
                tmp = dec[j];
        } 
        dec[i] = tmp + 1;
    }
    for (int i = 0; i < N; i++)
        ans = (ans > inc[i] + dec[i]) ? ans : inc[i] + dec[i];

    printf("%d", ans - 1);
}
