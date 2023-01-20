N = int(input())

arr = [[0]*N for _ in range(N)]
inputs = [list(map(int, input().split())) for _ in range(N**2)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N*N):
    students = inputs[i]
    a,b,c,d,e = inputs[i]
    #print([b,c,d,e])

    # print(a, students[0])
    # print([b,c,d,e], students[1:])
    info = []
    for j in range(N):
        for k in range(N):
            if not arr[j][k]:
                like = 0
                blank = 0
                # if 0 in [b,c,d,e]:
                #     print("yes")
                for d in range(4):
                    nx, ny = j+dx[d], k+dy[d]
                    if 0<=nx<N and 0<=ny<N:
                        if arr[nx][ny] in students[1:]:
                            #print(arr[nx][ny])
                            like += 1
                        elif arr[nx][ny] == 0:
                            blank += 1
                info.append([like, blank, j, k])

    info.sort(key=lambda x:(-x[0], -x[1], x[2], x[3]))
    arr[info[0][2]][info[0][3]] = students[0]

#print(arr)

inputs.sort()

satisfied = 0
for i in range(N):
    for j in range(N):
        student = arr[i][j]
        temp = 0
        for d in range(4):
            nx, ny = i+dx[d], j+dy[d]
            if 0<=nx<N and 0<=ny<N:
                if arr[nx][ny] in inputs[student-1]:
                    temp += 1
        if temp != 0:
            satisfied += 10**(temp-1)

print(satisfied)
