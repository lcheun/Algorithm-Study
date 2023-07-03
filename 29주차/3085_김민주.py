from collections import deque
import copy


N = int(input())
arr = [list(map(str, input())) for _ in range(N)]

dx = [1, 0]
dy = [0, 1]

def candy_count():
    answer = 1

    for i in range(N):
        # 행에 연속된 거 최대 몇갠지
        cnt = 1
        for j in range(1, N):
            if arr[i][j] == arr[i][j-1]:
                cnt += 1
            else:
                cnt = 1

            if cnt > answer:
                answer = cnt

        # 열에 연속된 거 최대 몇갠지
        cnt = 1
        for j in range(1, N):
            if arr[j][i] == arr[j-1][i]:
                cnt += 1
            else:
                cnt = 1

            if cnt > answer:
                answer = cnt

    return answer

max_count = 0

temp = copy.deepcopy(arr)
for i in range(N):
    for j in range(N):
        if j+1<N:
            # 바꿔치기
            arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]

            temp_max = candy_count()
            if temp_max > max_count:
                max_count = temp_max
            # 돌려 놓기
            arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]

        if i+1 < N:
            arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]

            temp_max = candy_count()
            if temp_max > max_count:
                max_count = temp_max

            arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]

print(max_count)


