L, C = map(int, input().split())
arr = list(input().split())
arr.sort()


answer = []
visited = [0]*C


def dfs(depth, start, password):
    if depth == L:
        if check(password):
            answer.append(password)
        return

    for i in range(start, C):
        if not visited[i]:
            visited[i] = 1
            dfs(depth+1, i+1, password+arr[i])
            visited[i] = 0


def check(password):
    ja = 0
    mo = 0
    for i in password:
        if i in ['a','e','o','u','i']:
            mo += 1
        else:
            ja += 1

    if mo>=1 and ja>=2:
        return True

    return False


dfs(0, 0, '')

for i in answer:
    print(i)