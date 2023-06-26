T = int(input())

# 오르막수랑 비슷한 문제

for _ in range(T):
    n = int(input())
    dp = [1 for _ in range(10)]
    # 첫상태 : 0, 1, 2,..., 9가 있으므로 1,1,1,1,...1

    # 각 배열의 현재 인덱스 이상의 원소값들을 더한다(마지막 수가 a라면 그거보다 크거나 같은 모든 수로 만들수 있으니까)
    for i in range(n-1):
        for j in range(10):
            dp[j] = sum(dp[j:])

    print(sum(dp))
