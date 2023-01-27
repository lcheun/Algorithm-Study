dx = [-1,1,0,0]
dy = [0,0,-1,1]

for _ in range(4):
    x1, y1, p1, q1, x2, y2, p2, q2 = map(int, input().split())

    #벗어남
    if p1<x2 or p2<x1 or y1>q2 or q1<y2:
        print('d')
    #하나 일치
    elif x1==p2 or x2==p1:
        # 두개 일치
        if q1==y2 or q2==y1:
            print('c')
        else:
            print('b')
    elif q1==y2 or q2==y1:
        print('b')
    # 그외
    else:
        print('a')
