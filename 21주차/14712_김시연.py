"""
뭔가 너무 오래걸릴거같아서 기믹을 써야하나 고민했는데
그냥 일반적인 백트래킹이었슴
어이없게도 python3로는 안되다가 pypy3로는 시간초과안남
"""
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[0] * (m + 1) for _ in range(n + 1)]
answer = 0


# 2x2가 생기지 않도록 (1,1)에서 끝까지 돌면서 배치
# 생기면 게임을 계속 진행해야함. 어차피 똑같은 과거로 되돌아가는거임
# 네모로 가득차게 되는 경우 count해주는 형식으로 진행
def dfs(x, y):
    global answer
    if x == 1 and y == n + 1:
        answer += 1
        return

    # 한 행을 다 돌았으면 다음으로
    if x == m:
        nx, ny = 1, y + 1
    # 그게 아니면 다음 열로
    else:
        nx, ny = x + 1, y

    dfs(nx, ny)

    # 2x2가 안되는경우 배치하고 다시 backtracking해서 돌아오면 없애주기
    if graph[y - 1][x] == 0 or graph[y - 1][x - 1] == 0 or graph[y][x - 1] == 0:
        graph[y][x] = 1
        dfs(nx, ny)
        graph[y][x] = 0


dfs(1, 1)
print(answer)
