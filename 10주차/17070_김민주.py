N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

dp = [[[0]*3 for _ in range(N)] for _ in range(N)] #[행][열][종류]

#0 : 가로 / 1 : 세로 / 2 : 대각선
for i in range(1, N):
    if arr[0][i] == 0:
        dp[0][i][0] = 1
    else:
        break

for i in range(1, N):
    for j in range(2, N):
        if arr[i][j] == 0:
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
        if arr[i][j] == 0 and arr[i-1][j] == 0 and arr[i][j-1] == 0:
            dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]

print(sum(dp[N-1][N-1]))