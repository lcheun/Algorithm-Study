"""
전에 봤던 2차원 누적합 카카오 문제랑 비슷
가능한 모든 k마다 최대 이익을 계산해서 업데이트 해야하는게 약간의 차이점
"""
import sys
input = sys.stdin.readline

n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i-1][j] + dp[i[j-1]] - dp[i-1][j-1] + matrix[i-1][j-1]

answer = dp[1][1]
for k in range(n):
    for i in range(1, n-k+1):
        for j in range(1, n-k+1):
            cur = dp[i+k][j+k] - dp[i-1][j+k] - dp[i+k][j-1] + dp[i-1][j-1]
            if answer < cur:
                answer = cur


print(answer)
