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
        # 구간합으로 구간합 구하는중,,, 모든 크기의 구간합을 구해야할때는 이렇게 하는게 편리하긴 할듯하다
        # 저번에는 입력이 주어지면 해당 구간합을 구해야 했으니까 좀 다른느낌이었음.
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1]

answer = dp[1][1]

# k에 대해서 이익이 어떤지 계산
for k in range(n):
    # kxk만큼만 수확 가능하니까, (n+1)-k까지만
    for i in range(1, n-k+1):
        for j in range(1, n-k+1):
            # 점화식 자체는 아까 위에랑 동일함
            cur = dp[i+k][j+k] - dp[i-1][j+k] - dp[i+k][j-1] + dp[i-1][j-1]
            if answer < cur:
                answer = cur


print(answer)
