import sys
input = sys.stdin.readline

s, p = map(int, input().split())
dna = input().rstrip()
a, c, g, t = map(int, input().split())

A, C, G, T = 0, 0, 0, 0
answer = 0


def add(next):
    global A, C, G, T

    if dna[next] == 'A':
        A += 1
    elif dna[next] == 'C':
        C += 1
    elif dna[next] == 'G':
        G += 1
    elif dna[next] == 'T':
        T += 1


def remove(start):
    global A, C, G, T

    if dna[start] == 'A':
        A -= 1
    elif dna[start] == 'C':
        C -= 1
    elif dna[start] == 'G':
        G -= 1
    elif dna[start] == 'T':
        T -= 1


def solution():
    global answer
    start, end = 0, p-1

    while end < s-1:
        remove(start)
        start+=1
        end+=1
        add(end)

        if A >= a and C >= c and G >= g and T >= t:
            answer += 1


for i in range(p):
    add(i)
if A >= a and C >= c and G >= g and T >= t:
    answer += 1

solution()
print(answer)
