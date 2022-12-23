from collections import deque
import sys

# 처음에 백트래킹으로 접근하려 했으나 bfs로 해결
# 방문 여부를 어떻게 체크하나 했는데 dictionary 사용 !! 새로운 아이디어
# => 만약 배열로 하면? 구차원 배열 ... 심지어 메모리 제한이 중요한 문제기 때문에 배열을 문자열로 바꾸고 dictionary를 사용하는 게 중요한 문제인 것 같다

arr = ""
for _ in range(3):
    a, b, c = map(str, sys.stdin.readline().split())
    arr+=a+b+c

visited = dict() # key : 퍼즐 모양 / val : 퍼즐 모양 만들기 위한 횟수

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs():
    q = deque([arr])
    visited[arr] = 0

    while q:
        now = q.popleft()

        if now == "123456780":
            return visited[now]

        empty = now.index('0')
        x = empty//3 #빈공간 x위치
        y = empty%3 #빈공간 y위치

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if 0<=nx<3 and 0<=ny<3:
                next_idx = nx*3+ny
                now_list = list(now)

                #빈 공간과 위치 바꿈
                now_list[empty], now_list[next_idx] = now_list[next_idx], now_list[empty]
                new = "".join(now_list)

                if not visited.get(new):
                    visited[new] = visited[now] + 1
                    q.append(new)

    return -1

print(bfs())