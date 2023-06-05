# 12886 돌 그룹

from collections import deque

a, b, c = map(int, input().split())
total = a+b+c
visited = [[0]*(total+1) for _ in range(total+1)]


def bfs():
    global a, b, c, total

    q = deque()
    q.append((a,b))
    visited[a][b] = 1

    while q:
        x, y = q.popleft()
        z = total-x-y #남은 돌 개수
        if x==y==z:
            return True

        # 그룹끼리 돌 개수 비교
        for a, b in (x, y), (y, z), (x, z):
            # 돌 개수에 따라 규칙대로
            if a<b:
                b-=a
                a+=a
            elif a>b:
                a-=b
                b+=b

            c = total-a-b #돌을 분배한 후 남은 그룹의 돌개수
            x = min(a,b,c)
            y = max(a,b,c)

            # 아직 분배한 적 없는 조합이면
            if not visited[x][y]:
                q.append((x, y))
                visited[x][y] = 1

    return False


# 돌의 총 개수가 3의 배수가 아니면 애초에 나눌 수 없음
if total%3!=0:
    print(0)
else:
    if bfs():
        print(1)
    else:
        print(0)