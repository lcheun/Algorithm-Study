"""
d가 node의 개수고, n이 가중치 있는 간선!
n간선이 없는 node들은 서로 1로 연결돼있음
2->10가는거하고, 5->50가는거하고 당연 후자가 이득이니까 지름길 있다고 다 가면 안됨
위치마다 최선값을 저장하는 dp로 풀자
+ 일방통행이니까 무조건 시작위치가 앞임
"""
import sys
input = sys.stdin.readline

n, d = map(int, input().split())
dp = [i for i in range(d+1)]
graph = [list(map(int, input().split())) for _ in range(n)]

#어차피 12개니까 지름길은 리스트로 저장
for i in range(d+1):
    dp[i] = min(dp[i], dp[i-1]+1)

    for s, e, l in graph:
        if i == s and e<= d and dp[i] + l < dp[e]:
            dp[e] = dp[i] + l


print(dp[d])
