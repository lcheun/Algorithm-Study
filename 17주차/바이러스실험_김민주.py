import sys
from heapq import heappush, heappop

input = sys.stdin.readline
n,m,k = map(int, input().split())

plus = [list(map(int, input().strip().split())) for _ in range(n)] # 4단계 양분 더하는 개수
virus = [[[] for _ in range(n)] for _ in range(n)] # 위치당 바이러스 배열 - 우큐
arr = [[5]*n for _ in range(n)] # 양분 남은 거


# 각 위치에 바이러스 나이 기준으로 우큐에 넣는다.
for _ in range(m):
    i, j, x = map(int, input().strip().split())
    heappush(virus[i-1][j-1], x)


# 1단계 : 양분 섭취
def eat():
    change = [[0]*n for _ in range(n)] #모든 바이러스가 섭취 끝낸 후 더할 죽은 바이러스 양
    five = [[0]*n for _ in range(n)] #5의 배수 개수
    for i in range(n):
        for j in range(n):
            new_heap = [] # 새로 업뎃될 우큐
            while virus[i][j]:
                v = heappop(virus[i][j])
                # 바이러스가 먹을 양분이 있는 경우
                if arr[i][j] >= v:
                    arr[i][j] -= v
                    v += 1
                    heappush(new_heap, v)
                # 바이러스 못 먹음
                else:
                    change[i][j] += (v//2)
            virus[i][j] = new_heap
    
    # 2단계 : 죽은 바이러스 -> 양분
    # 3단계에서 사용할 5의 배수 개수도 같이 구함
    for i in range(n):
        for j in range(n):
            arr[i][j] += change[i][j]
            for v in virus[i][j]:
                if v%5 == 0:
                    five[i][j] += 1
    return five

dx = [-1, 1, 0, 0, -1, 1, -1, 1]
dy = [0, 0, -1, 1, 1, -1, -1, 1]
# 3단계 : 번식
def birth(five):
    for i in range(n):
        for j in range(n):
            if five[i][j]>0:
                for d in range(8):
                    nx, ny = i+dx[d], j+dy[d]
                    if 0<=nx<n and 0<=ny<n:    
                        # 5의 배수인 개수만큼 우큐에 1 넣어줌
                        for k in range(five[i][j]):
                            heappush(virus[nx][ny], 1)

# 4단계 : 양분 더하기
def food_add():
    for i in range(n):
        for j in range(n):
            arr[i][j] += plus[i][j]                     


# 살아있는 바이러스 개수 체크
def life_check():
    count = 0
    for i in range(n):
        for j in range(n):
            count += len(virus[i][j])

    return count
# f = eat()
# birth(f)
# print(arr)
# print(virus)

for _ in range(k):
    f = eat()
    birth(f)
    food_add()
    
answer = life_check()
print(answer)
