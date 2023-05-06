# 평범한 배낭
# dp

N, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dp = [[-1]*(K+1) for _ in range(N)] # dp[살펴본 물건 idx][남은 담을 수 있는 무게]

def recur(i, k):
    if i<0:
        return 0

    if dp[i][k]==-1:
        # 물건을 담을 수 없는 경우(무게 초과)
        if k<arr[i][0]:
            dp[i][k] = recur(i-1, k)
        # 물건을 담을 수 있는 경우
        else:
            # 이번 인덱스의 물건을 담지 않는 경우 vs 물건을 담은 경우(=> 담을 수 있는 무게 빼기 & 담은 가치 추가)
            dp[i][k] = max(recur(i-1,k), recur(i-1, k-arr[i][0])+arr[i][1])

    return dp[i][k]

print(recur(N-1, K))
