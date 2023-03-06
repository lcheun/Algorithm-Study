'''
뭔가 살펴봤을때는 딱히 방도가 없어보여서 그냥 재귀로 풀면될거같음
'''

import sys
input = sys.stdin.readline


def solution(data):
    if len(data) == 1:
        return data[0][0]

    count = len(data)//2
    new_data = [[0 for j in range(count)] for i in range(count)]

    for i in range(count):
        for j in range(count):
            x = j*2
            y = i*2
            list = sorted([data[y][x], data[y][x+1], data[y+1][x], data[y+1][x+1]], reverse=True)
            new_data[i][j] = list[1]

    answer = solution(new_data)
    return answer


if __name__ == '__main__':
    output = 0
    n = int(input())
    data = [[] for i in range(n)]

    for i in range(n):
        data[i] = list(map(int, input().split()))

    output = solution(data)
    print(output)
