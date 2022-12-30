import sys

n = int(input())
arr = list(map(int, input().split()))

dp = [[0]*2 for _ in range(n)]
dp[0][0] = arr[0] #초기화 (하나 이상 골라야 하니까)

if n>1:
    answer = -1*sys.maxsize

    #최댓값을 구하는 거기 때문에 자기랑 이전 기록을 더한 값이 자신보다 작으면 그 앞의 값은 의미가 없다
    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]) #원소 제거하지 않는 경우
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]) #원소 제거한 경우 1. 이전에서 원소 제거 2. 내 원소 제거

        answer = max(answer, dp[i][0], dp[i][1])

    print(answer)
else:
    print(dp[0][0])
