"""
스도쿠 룰: 1) 가로/세로줄에서 숫자 하나씩만 2)3x3판에서 숫자 하나씩만 존재해야함
빈칸은 null값이 아니고 0으로 주어진다는 점
효율적으로 풀 수 있는 방법이 있는가? -> 딱히 적용할 수 있는 알고리즘은 없는것같음
=> 스도쿠는 한칸씩 채워보면서 안되면 지우고 다시하니까 백트래킹으로 풀어보자
"""

import sys
from collections import deque
input = sys.stdin.readline


def init():
    global puzzle, row, col, square, blank
    for i in range(9):
        arr = list(map(int, input().split()))
        puzzle.append(arr)

        for j in range(9):
            if arr[j] == 0:
                blank.append((i, j))
            else:
                sq = (i // 3) * 3 + j // 3
                square[sq][arr[j]] = arr[j]
                row[i][arr[j]] = arr[j]
                col[j][arr[j]] = arr[j]


def add_check(now, sq, num):
    global row, col, square, puzzle
    puzzle[now[0]][now[1]] = num
    row[now[0]][num] = num
    col[now[1]][num] = num
    square[sq][num] = num


def pop_check(now, sq, num):
    global row, col, square, puzzle
    puzzle[now[0]][now[1]] = 0
    row[now[0]].pop(num)
    col[now[1]].pop(num)
    square[sq].pop(num)


def solution(idx):
    global puzzle, row, col, square, blank

    # 다 탐색했다면
    if idx == len(blank):
        for i in range(9):
            print(' '.join(map(str, puzzle[i])))
        sys.exit()

    now = blank[idx]
    sq = (now[0] // 3) * 3 + now[1]//3

    for num in range(1, 10):
        if num not in row[now[0]] and num not in col[now[1]] and num not in square[sq]:
            add_check(now, sq, num)
            solution(idx+1)
            pop_check(now, sq, num)


# main():
puzzle = []
blank = []
row = [{} for _ in range(9)]
col = [{} for _ in range(9)]
square = [{} for _ in range(9)]

init()
solution(0)



