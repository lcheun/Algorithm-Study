"""
그래프에서 사이클이 없는, 가중치가 가장 작은 트리를 만들어야하는 문제
그걸 그냥 별자리로 비유한것 -> 최소 스패닝 트리 문제
방법은 - kruskal하고 prim이 있음
-> 주어진 시작점이 없고, 100C2 조합은 4000대니까 kruskal로 하겠음
두 좌표 사이의 거리를 구하는 공식,,,너무 오랜만이다 나 수학몰라 ^^ -> ((x1-x2)^2 + (y1-y2)^2)**(1/2)임
"""

import sys
import heapq
from math import pow, sqrt
input = sys.stdin.readline
parent = []


def find_parent(x):
    if parent[x] < 0:
        return x

    parent[x] = find_parent(parent[x])
    return parent[x]


def solution(n, weights):
    answer = 0
    count = 0

    while weights:
        data = heapq.heappop(weights)
        weight = data[0]
        x, y = data[1], data[2]
        px = find_parent(x)
        py = find_parent(y)

        if px == py:
            continue
        else:
            parent[px] += parent[py]
            parent[py] = px
            count += 1
            answer += data[0]

        if count == n-1:
            break

    return answer


if __name__ == "__main__":
    n = int(input())
    star = []
    weights = []
    parent = [-1 for _ in range(n)]

    for i in range(n):
        x, y = map(float, input().split())
        star.append((x, y))

    for i in range(n):
        for j in range(i + 1, n):
            x1, y1 = star[i]
            x2, y2 = star[j]
            weight = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))
            heapq.heappush(weights, (weight, i, j))

    output = solution(n, weights)
    print(round(output, 2))
