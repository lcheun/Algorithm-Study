T = int(input())

# dp

for _ in range(T):
    N = int(input())

    coin = list(map(int, input().split()))
    make = int(input()) # 만들어야하는 코인

    dp = [1]+[0 for _ in range(make)]
    for c in coin:
        # i라는 금액을 만들 때 c 동전 사용하는 경우 더하기
        for i in range(c, make+1):
            dp[i] += dp[i-c]

    print(dp[make])