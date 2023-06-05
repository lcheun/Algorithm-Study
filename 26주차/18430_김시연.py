"""
정확한 방법론은 없는거같아서, 그냥 다 탐색하면 될것같음..?
"""
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
shape = {0: [0, -1, 1, 0], 1: [-1, 0, 0, -1], 2: [-1, 0, 0, 1], 3: [0, 1, 1, 0]}
visited = [[False for _ in range(m)] for _ in range(n)]
answer = 0


def dfs(i, j, sum):
    global answer

    # 다음행 탐색
    if j == m:
        i += 1
        j = 0

    # 마지막 행이면, max를 정답으로 넣어주고 반환
    if i == n:
        answer = max(answer, sum)
        return

    # 현재 자리가 방문한적 없다면 부메랑 모양 계산
    if not visited[i][j]:
        for k in range(4):
            a, b, c, d = shape[k]
            x1, y1, x2, y2 = i + a, j + b, i + c, j + d

            # 범위 안이고, 방문기록이 없다면 다음 dfs진행
            if 0 <= x1 < n and 0 <= x2 < n and 0 <= y1 < m and 0 <= y2 < m:
                if not visited[x1][y1] and not visited[x2][y2]:
                    visited[x1][y1] = visited[x2][y2] = visited[i][j] = True
                    dfs(i, j + 1, sum + board[i][j] * 2 + board[x1][y1] + board[x2][y2])
                    visited[i][j] = visited[x1][y1] = visited[x2][y2] = False

    # 현재 위치에서 가능한 부메랑 조합이 없다면 다음 좌표 탐색
    dfs(i, j + 1, sum)


dfs(0, 0, 0)
print(answer)
