import sys

input = sys.stdin.readline
arr = []
empty = []

for i in range(9):
    temp = list(map(int, input().split()))
    for j in range(9):
        if temp[j]==0:
            empty.append((i,j))
    arr.append(temp)


flag = False
visited = [0 for _ in range(len(empty))]
def dfs(depth):
    global flag

    if depth == len(empty):
        flag = True
        return

    row = empty[depth][0]
    col = empty[depth][1]

    for i in range(1, 10):
        if check(row, col, i) and not visited[depth]:
            arr[row][col] = i
            visited[depth] = 1
            dfs(depth+1)
            if flag:
                return
            else:
                arr[row][col] = 0
                visited[depth] = 0


def check(row, col, num):
    for i in range(0, 9):
        if arr[row][i] == num:
            return False

    for i in range(0, 9):
        if arr[i][col] == num:
            return False

    for i in range((row//3)*3, (row//3)*3+3):
        for j in range((col//3)*3, (col//3)*3+3):
            if arr[i][j] == num:
                return False

    return True


dfs(0)

for a in arr:
    print(*a)