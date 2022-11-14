import sys
N = int(input())
P = [0]+list(map(int, input().split()))
MAX_VAL = sys.maxsize
dp = [0]+[MAX_VAL for _ in range(N+1)] # index장째 구매한 경우 최적 가격

#i : 지금까지 구매한 카드 총 장수
#j : 지금 구매할지 말지 선택할 카드 종류
for i in range(1, N+1):
    for j in range(1, i+1):
        dp[i] = min(dp[i], dp[i-j]+P[j])

print(dp[N])