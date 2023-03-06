import math
import sys

input = sys.stdin.readline
arr = []

while True:
    num = int(input())
    if num==0:
        break

    arr.append(num)

max_val = max(arr)

prime = [False, False] + [True]*(max_val-1)


for i in range(2, int(math.sqrt(max_val))+1):
    if prime[i]:
        j = 2
        while i*j < len(prime):
            prime[i*j] = False
            j += 1

for i in arr:
    for j in range(2, i-1):
        if prime[i-j] and prime[j]:
            print(i,"=",j,'+',(i-j))
            break

