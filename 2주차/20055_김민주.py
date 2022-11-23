
N, K = map(int, input().split())

A = list(map(int, input().split()))

k_count = A.count(0) #내구도가 0인 칸 개수
answer = 0

robot = [0 for _ in range(N)]


def rotate(arr):
    temp = arr[-1]
    arr[1:] = arr[0:len(arr)-1]
    arr[0] = temp


def down():
    if robot[N-1]==1:
        robot[N-1] = 0

while k_count < K:
    answer += 1

    rotate(robot)
    rotate(A)
    down()
    # r이 올라가 있는 칸 0~2N-1
    for i in range(len(robot)-1,-1,-1):
        r = robot[i]

        if r==1 and A[i+1]>0 and not robot[i+1]:
            robot[i+1] = 1
            robot[i] = 0
            A[i+1] -= 1
            down()

    if A[0]>0 and not robot[0]:
        A[0] -= 1
        robot[0] = 1

    k_count = A.count(0)

print(answer)