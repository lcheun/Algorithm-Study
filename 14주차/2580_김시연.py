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
    global puzzle, blank
    for i in range(9):
        arr = list(map(int, input().split()))
        puzzle.append(arr)

        for j in range(9):
            if arr[j] == 0:
                blank.append((i, j))


def get_candidate(i, j):
    global puzzle
    candidate = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    for idx in range(9):
        if puzzle[i][idx] in candidate:
            candidate.remove(puzzle[i][idx])
        if puzzle[idx][j] in candidate:
            candidate.remove(puzzle[idx][j])

    for x in range((i//3)*3, (i//3+1)*3):
        for y in range((j//3)*3, (j//3+1)*3):
            if puzzle[x][y] in candidate:
                candidate.remove(puzzle[x][y])
    return candidate


def solution(idx):
    global puzzle, blank

    # 다 탐색했다면
    if idx == len(blank):
        for i in range(9):
            print(' '.join(map(str, puzzle[i])))
        sys.exit()

    now = blank[idx]
    candidate = get_candidate(now[0], now[1])

    for num in candidate:
        puzzle[now[0]][now[1]] = num
        solution(idx + 1)
        puzzle[now[0]][now[1]] = 0


# main():
puzzle = []
blank = []

init()
solution(0)



