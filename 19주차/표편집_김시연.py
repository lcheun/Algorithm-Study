import sys
input = sys.stdin.readline

table = {}
deleted = []

def solution(n, k, cmd):
    global table, deleted
    answer = ['O']*n
    cur = k
    table = {i: [i - 1, i + 1] for i in range(n)}

    # key-idx, [이전, 이후]
    table[0] = [None, 1]
    table[n-1] = [n-2, None]

    for c in cmd:
        if c == "C":
            answer[cur] = "X"
            prev, next = table[cur]
            deleted.append([prev, cur, next])

            # 지운값이 마지막이었을 경우
            if next == None:
                cur = table[cur][0]
            else:
                cur = table[cur][1]

            # 이웃값들의 이웃정보 수정
            if prev == None:
                table[next][0] = None
            elif next == None:
                table[prev][1] = None
            else:
                table[prev][1] = next
                table[next][0] = prev

        elif c == "Z":
            # 이런식으로 복구하면 만약 지워진 애의 prev, next도 지워졌으면
            # 위치를 못찾는거 아닌가 했는데 생각해보니까 stack형식으로 복구함
            # 즉 now가 꺼내질 시점에는 혹여나 prev, next가 지워졌었더라도
            # 복구되어있는 상태라는거임
            prev, now, next = deleted.pop()
            answer[now] = "O"

            if prev == None:
                table[next][0] = now
            elif next == None:
                table[prev][1] = now
            else:
                table[next][0] = now
                table[prev][1] = now

        else:
            direct, x = c.split(' ')
            x = int(x)

            if direct == "D":
                for _ in range(x):
                    cur = table[cur][1]
            else:
                for _ in range(x):
                    cur = table[cur][0]

    return ''.join(answer)