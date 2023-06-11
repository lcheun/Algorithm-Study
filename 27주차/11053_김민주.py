import sys

input = sys.stdin.readline
N = int(input())
A = list(map(int, input().strip().split()))
dp = [0 for _ in range(N)]


def calc(n):
    if not dp[n]:
        dp[n] = 1
        for i in range(n):
            if A[i]<A[n]:
                dp[n] = max(calc(i)+1, dp[n]) # 부분 수열 최대값 갱신(재귀)

    return dp[n]

for i in range(N):
    calc(i)

max_val = max(dp)
print(max_val)

