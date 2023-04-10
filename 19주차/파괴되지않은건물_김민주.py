def solution(board, skill):
    answer = 0
    
    sum_arr = [[0]*(len(board[0])+1) for _ in range(len(board)+1)]
    
    for t, x1, y1, x2, y2, degree in skill:
        sum_arr[x1][y1] += degree if t==2 else -degree
        sum_arr[x1][y2+1] += -degree if t==2 else degree
        sum_arr[x2+1][y1] += -degree if t==2 else degree
        sum_arr[x2+1][y2+1] += degree if t==2 else -degree
    
    for i in range(len(sum_arr)-1):
        for j in range(len(sum_arr[0])-1):
            sum_arr[i][j+1] += sum_arr[i][j]
    
    for j in range(len(sum_arr[0])-1):
        for i in range(len(sum_arr)-1):
            sum_arr[i+1][j] += sum_arr[i][j]
    
    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += sum_arr[i][j]
            
            if board[i][j] > 0:
                answer += 1
    
    # for b in board:
    #     print(*b)
    return answer
