"""
도둑루피라는 가중치가 있고(음수지만) 잃는 금액을 최소로 하는 루트를 찾아야함
-> 소지금을 "잃는다"에 치중하지말고 도둑루피의 개수를 최소화한다고하면 최단루트 문제임
-> 다익스트라로 풀어보자: 현재노드에서 가장 근접한 애 방문 -> 최단 배열 업데이트하기
"""
import sys
import heapq
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = int(1e9)


def solution():
    que = []
    heapq.heappush(que, (cave[0][0], 0, 0))
    rupee[0][0] = 0

    while que:
        cost, x, y = heapq.heappop(que)

        if x == n-1 and y == n-1:
            print(f'Problem {cnt}: {rupee[x][y]}')
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                ncost = cost + cave[nx][ny]
                if ncost < rupee[nx][ny]:
                    rupee[nx][ny] = ncost
                    heapq.heappush(que, (ncost, nx, ny))


cnt = 1

while True:
    n = int(input())
    if n == 0:
        break

    cave = [list(map(int, input().split())) for _ in range(n)]
    rupee = [[INF for _ in range(n)]for _ in range(n)]

    solution()
    cnt += 1