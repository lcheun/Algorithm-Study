import sys

input = sys.stdin.readline
N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]


def make_arr(size, new_arr):
    #222-풀링 종료
    if size==1:
        print(new_arr[0][0])
        return

    temp_arr = [[0]*(size//2) for _ in range(size//2)]

    # 두칸씩 증가해가면서 2x2에서 가장 큰 값 찾는다.
    for i in range(0, size-1, 2):
        for j in range(0, size-1, 2):
            four = [new_arr[i][j], new_arr[i+1][j], new_arr[i][j+1], new_arr[i+1][j+1]]
            four.sort()
            temp_arr[i//2][j//2] = four[-2] # 다음 배열의 위치에 넣어준다.

    make_arr(size//2, temp_arr)


make_arr(N, arr)