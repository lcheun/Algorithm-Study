N = int(input())
target = list(input())
answer = 0

for _ in range(N-1):
    compare = target[:] 
    word = input()
    cnt = 0

    for w in word:
        if w in compare:
            compare.remove(w)
        else:
            cnt += 1

    if cnt < 2 and len(compare) < 2:
        answer += 1

print(answer)