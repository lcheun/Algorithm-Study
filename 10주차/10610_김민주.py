N = input()
N = sorted(N, reverse=True) #가장 큰수 만들기

sum_ = 0
for i in N:
    sum_ += int(i)

if sum_%3!=0 and N[-1]!=0:
    print(-1)
else:
    print(''.join(N))