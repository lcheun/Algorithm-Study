import sys
n=int(input())
A=list(map(int,sys.stdin.readline().split()))

sum = [i for i in A] #for i in v: print(i)를 한 줄로, type은 int 아닌 list로
sum2 = [i for i in A]

#sum=A #sum[i]=i번째 원소를 마지막으로 하는 가장 큰 연속합
#sum2=A 둘의 차이를 모르겠음
#print(sum, sum2)
for i in range(1,n):
    sum[i]=max((sum[i-1]+A[i]),A[i]) #sum[i]=i번째 원소를 마지막으로 하는 가장 큰 연속합
    #sum[i]+A[i+1]와 A[i+1] 비교해서 큰거
for i in range(n-2, 1, -1): #거꾸로
    #print(i)
    sum2[i]=max((sum2[i+1]+A[i]),A[i]) #

max1=max(sum)
max2=-1001

for i in range(1, n-1):
    max2=max(max2,sum[i-1]+sum2[i+1])

print(max(max1,max2))