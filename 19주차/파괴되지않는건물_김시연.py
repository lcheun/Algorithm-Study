def solution(board, skill):
    answer = 0
    tmp = [[0 for _ in range(len(board[0]) + 1)] for _ in range(len(board) + 1)]

    for type, x1, y1, x2, y2, num in skill:
        x_max, y_max = x2 + 1, y2 + 1

        tmp[x1][y1] += num if type == 2 else -num
        tmp[x_max][y1] += -num if type == 2 else num
        tmp[x1][y_max] += -num if type == 2 else num
        tmp[x_max][y_max] += num if type == 2 else -num

    for i in range(len(tmp) - 1):
        for j in range(len(tmp[0]) - 1):
            tmp[i][j + 1] += tmp[i][j]

    for j in range(len(tmp[0]) - 1):
        for i in range(len(tmp) - 1):
            tmp[i + 1][j] += tmp[i][j]

    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += tmp[i][j]
            if board[i][j] > 0:
                answer += 1

    return answer