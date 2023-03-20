"""
맨 왼쪽 위에서 시작하고, 오른쪽하고 아래만으로만 갈 수 있는게 딱 전형적인 bfs문제
다만, 칸에 쓰여있는 수만큼 이동한다는게 다른점인듯
-> 근데 어차피 최단을 구하는게 아니니까 easy
-> 오른쪽하고 아래만 가니까 visited check안해도된다고 생각했는데 안해주니까 메모리초과함
-> 생각해보니 아래->오른쪽 == 오른쪽->아래니까 그럴 수 있음
"""

import sys
from collections import deque
input = sys.stdin.readline


def solution(n, data):
    visited = [[False for _ in range(n)] for _ in range(n)]
    deq = deque()
    deq.append((0, 0))

    while deq:
        x, y = deq.popleft()
        now = data[x][y]
        if now == -1:
            return "HaruHaru"

        if y+now < n and not visited[x][y+now]:
            deq.append((x, y+now))
            visited[x][y+now] = True
        if x+now < n and not visited[x+now][y]:
            deq.append((x+now, y))
            visited[x+now][y] = True

    return "Hing"


if __name__ == "__main__":
    n = int(input())
    data = [[] for _ in range(n)]

    for i in range(n):
        data[i] = list(map(int, input().split()))

    print(solution(n, data))

