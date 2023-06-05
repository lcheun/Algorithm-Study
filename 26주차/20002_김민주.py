N = int(input())

dp = [[-1001]*(N+1) for _ in range(N+1)]

# i,j 까지의 구간합
for i in range(1, N+1):
    arr = list(map(int, input().split()))
    for j in range(1, N+1):
        dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + arr[j-1]

max_val = dp[0][0]

# 정사각형으로 자르기
for k in range(N):
    for i in range(1, N-k+1):
        for j in range(1, N-k+1):
            # 시작점 i,j / 끝점 i+k, j+k 인 정사각형의 총이익
            profit = dp[i+k][j+k] - dp[i-1][j+k] - dp[i+k][j-1] + dp[i-1][j-1]
            max_val = max(max_val, profit) # 최대 총 이익 업데이트

print(max_val)
