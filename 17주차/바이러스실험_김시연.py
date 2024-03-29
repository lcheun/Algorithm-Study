import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
extra = [list(map(int, input().split())) for _ in range(n)]

virus = [[[] for _ in range(n)] for _ in range(n)]
new_virus = [[[] for _ in range(n)] for _ in range(n)]
food = [[0 for _ in range(n)] for _ in range(n)]
new_food = [[0 for _ in range(n)] for _ in range(n)]


# 번식하는 부분
def child(cx, cy):
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]

    for x, y in zip(dx, dy):
        nx, ny = cx + x, cy + y

        if 0 <= nx < n and 0 <= ny < n:
            new_virus[nx][ny].append(1)


def simulation():
    # 초기화
    for i in range(n):
        for j in range(n):
            new_virus[i][j] = []
            new_food[i][j] = 0

    # step1) 음식 섭취
    for i in range(n):
        for j in range(n):
            virus[i][j].sort()

            # 나이만큼 먹을 수 있으면 new에 넣고, 아니면 음식 추가
            for age in virus[i][j]:
                if food[i][j] >= age:
                    food[i][j] -= age
                    new_virus[i][j].append(age + 1)
                else:
                    new_food[i][j] += age // 2

            new_food[i][j] += food[i][j]

    # step2) 번식
    for i in range(n):
        for j in range(n):
            for age in new_virus[i][j]:
                # 5의 배수인 경우에만 번식
                if age % 5 == 0:
                    child(i, j)


    # step3) 추가양분 제공하기 -> 입력받았던거
    for i in range(n):
        for j in range(n):
            new_food[i][j] += extra[i][j]

    # step4) temp에서 기존 배열로 옮기기
    for i in range(n):
        for j in range(n):
            virus[i][j] = new_virus[i][j][:]
            food[i][j] = new_food[i][j]


# input
# 초기 바이러스 값 받기
for _ in range(m):
    r, c, a = map(int, input().split())
    virus[r - 1][c - 1].append(a)

# 첫 음식 넣어주기
for i in range(n):
    for j in range(n):
        food[i][j] = 5

for _ in range(k):
    simulation()

answer = sum([len(virus[i][j]) for i in range(n) for j in range(n)])
print(answer)
