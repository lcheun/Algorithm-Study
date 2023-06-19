"""
자기 자신(30)보다 작은 숫자들 중 가장 큰 길이를 구하고 그 길이에 +1
"""
n = int(input())
a = list(map(int, input().split()))
dp = [0 for i in range(n)]
for i in range(n):
    for j in range(i):
        if a[i] > a[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1
print(max(dp))
