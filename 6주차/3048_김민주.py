N1, N2 = map(int, input().split())
group1 = list(input())
group2 = list(input())

arr = []
for i in group1[::-1]:
    arr.append((i,0))
for i in group2:
    arr.append((i,1))

T = int(input())

while T:
    T -= 1
    index = []
    for i in range(len(arr)-1):
        if arr[i][1]==0 and arr[i+1][1]==1: #group1 개미들을 기준으로
            index.append(i) #여기서 그냥 바꾸면 바뀌었던 게 계속 다음 반복에서 바뀌기 때문에 index배열에 담은 다음에 한번에 바꾼다
    for i in index:
        arr[i], arr[i+1] = arr[i+1], arr[i] #swap
for i, j in arr:
    print(i, end='')