import sys

input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
order, visited = [0 for _ in range(9)], [0 for _ in range(9)]
order[3] = 0
visited[3] = 1
answer = 0

def dfs(cnt):
    global answer

    #조합 끝
    if cnt == 9:
        now, score = 0, 0
        for inning in arr:
            out, b1, b2, b3 = 0, 0, 0, 0

            while out < 3:
                batter = order[now]
                if inning[batter] == 0:
                    out += 1
                elif inning[batter] == 1:
                    score += b3
                    b1, b2, b3 = 1, b1, b2
                elif inning[batter] == 2:
                    score += b2+b3
                    b1, b2, b3 = 0, 1, b1
                elif inning[batter] == 3:
                    score += b1+b2+b3
                    b1, b2, b3 = 0, 0, 1
                elif inning[batter] == 4:
                    score += b1+b2+b3+1
                    b1, b2, b3 = 0, 0, 0

                now += 1
                now %= 9

        answer = max(answer, score)
        return

    #조합
    for i in range(9):
        if visited[i]:
            continue
        visited[i] = 1
        order[i] = cnt
        dfs(cnt+1)
        visited[i] = 0
        order[i] = 0


dfs(1)
print(answer)