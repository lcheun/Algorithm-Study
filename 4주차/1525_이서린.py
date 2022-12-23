##BFS

import sys
from collections import deque

def bfs():
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    queue = deque([graph])
    visited[graph] = 0

    while queue:
        target = queue.popleft()
        if target == "123456780":
            return visited[target]

        idx = target.find("0") 
        x = idx // 3
        y = idx % 3 

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < 3 and 0 <= ny < 3:
                n = nx * 3 + ny 
                list_target = list(target)

                list_target[idx], list_target[n] = list_target[n], list_target[idx]
                new_target = "".join(list_target)

                if not visited.get(new_target):
                    visited[new_target] = visited[target] + 1
                    queue.append(new_target)

    return -1

graph = ""
for _ in range(3):
    a, b, c = map(str, sys.stdin.readline().split())
    graph += a + b + c
visited = dict()
print(bfs())