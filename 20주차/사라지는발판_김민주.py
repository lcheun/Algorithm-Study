def solution(board, aloc, bloc):
    answer = -1
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    def can_move(x, y):
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<len(board) and 0<=ny<len(board[0]):
                if board[nx][ny]!=0:
                    return True
        return False
    def dfs(x1,y1,x2,y2,turn,move):
        nonlocal answer
        if turn == 0 and (not can_move(x1, y1) or board[x1][y1]==0):
            answer = max(answer, move)
            return 1-turn, move # 승자 & 이동 횟수
        if turn == 1 and (not can_move(x2, y2) or board[x2][y2]==0):
            answer = max(answer, move)
            return 1-turn, move
        
        win = []
        lose = []
        
        # 현재 턴이 0번 플레이어인 경우
        if turn == 0:
            for i in range(4):
                nx, ny = x1+dx[i], y1+dy[i]
                if 0<=nx<len(board) and 0<=ny<len(board[0]):
                    if board[nx][ny]!=0:
                        board[x1][y1] = 0
                        who_win, move_cnt = dfs(nx, ny, x2, y2, 1, move+1)
                        # 이긴 경우
                        if who_win == 0:
                            win.append(move_cnt)
                        # 진 경우
                        else:
                            lose.append(move_cnt)
                        board[x1][y1] = 1
        # 현재 턴이 1번 플레이어인 경우
        if turn == 1:
            for i in range(4):
                nx, ny = x2+dx[i], y2+dy[i]
                if 0<=nx<len(board) and 0<=ny<len(board[0]):
                    if board[nx][ny]!=0:
                        board[x2][y2] = 0
                        who_win, move_cnt = dfs(x1, y1, nx, ny, 0, move+1)
                        if who_win == 1:
                            win.append(move_cnt)
                        else:
                            lose.append(move_cnt)
                        board[x2][y2] = 1

        # 현재 턴이 이긴 경우
        if win:
            return turn, min(win)
        # 현재 턴이 진 경우
        else:
            return 1-turn, max(lose)
        
    winner, move_ans = dfs(aloc[0],aloc[1],bloc[0],bloc[1],0,0)
    answer = move_ans
    
    return answer
