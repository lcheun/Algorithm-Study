arr = [list(map(int, input().split())) for _ in range(9)]

def check(row, col, num):
    # 가로줄(열)
    for i in range(9):
        if arr[row][i] == num:
            return False

    # 세로줄(행)
    for i in range(9):
        if arr[i][col] == num:
            return False

    # 칸
    block_row = (row//3)*3
    block_col = (col//3)*3
    for i in range(block_row, block_row+3):
        for j in range(block_col, block_col+3):
            if arr[i][j] == num:
                return False

    return True


# check가 False를 리턴하면 중간에 백해야 한다.
def solve(row, col):
    #다음줄로
    if col==9:
        solve(row+1, 0)
        return #이거 없으면 index 에러

    #끝 -> 답 출력하고 종료
    if row==9:
        for i in arr:
            print(*i)
        exit(0) # return 으로 하면 틀림

    if arr[row][col]==0:
        for num in range(1,10):
            if check(row,col,num): # 만약 check False면 다음 재귀로 들어가지 못하고 반복문 돈다(1~9에 대해 모두 체크)
                # 만약 들어갈 수 있는 숫자면 다음 재귀로 들어간다
                # 채운 값들이 다다다 옳은 값이면 계속 재귀로 들어가다가 col==9, row==9까지 들어감 -> 답 출력 후 리턴
                arr[row][col] = num
                solve(row, col+1)

        #만약 1~9 중에 들어갈 수 있는 값이 없었다면 지금까지 채운 스도쿠 답이 틀린 답이니까 백
        arr[row][col] = 0
        return

    # 0 아닌 경우 다음 탐색~
    solve(row, col+1)

solve(0,0)