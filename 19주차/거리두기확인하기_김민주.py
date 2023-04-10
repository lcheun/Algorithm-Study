def solution(places):
    answer = []
    
    for p in places:
        # 사람인 경우 인덱스 i, j 를 담는다
        persons = []
        for i in range(len(p)):
            for j in range(len(p[i])):
                if p[i][j]=='P':
                    persons.append((i,j))
        
        # 맨해튼 거리가 2 이하인 사람들에 대한 정보를 temp에 담는다
        temp = [[] for _ in range(len(persons))]
        for i in range(len(persons)):
            for j in range(i+1, len(persons)):
                if abs(persons[i][0]-persons[j][0])+abs(persons[i][1]-persons[j][1]) <= 2:
                    temp[i].append(j)
        
        turn_ans = 1
        # 사람마다 거리가 2 이하인 사람들(temp[i])에 대해 규칙 체크
        for i in range(len(persons)):
            # 한명이라도 규칙 어긴 경우 break
            if turn_ans==0:
                break
            for j in temp[i]:
                x1, y1 = persons[i]
                x2, y2 = persons[j]
                
                # 대각선으로 앉아 있는 경우
                if x1!=x2 and y1!=y2:
                    # 빈공간에 가림막이 없으면 0
                    if p[x1][y2]!='X' or p[x2][y1]!='X':
                        turn_ans = 0
                        break
                # 같은 행에 앉은 경우
                elif x1==x2:
                    min_y = min(y1, y2)
                    max_y = max(y1, y2)
                    flag = False
                    # 각 열에 가림막이 하나도 없으면 0
                    for y in range(min_y+1, max_y):
                        if p[x1][y]=='X':
                            flag = True
                            break
                    if not flag:
                        turn_ans = 0
                        break
                # 같은 열에 앉은 경우(같은행에 앉은 경우와 로직 동일)
                elif y1==y2:
                    min_x = min(x1, x2)
                    max_x = max(x1, x2)
                    flag = False
                    # 각 행에 가림막이 하나도 없으면 0
                    for x in range(min_x+1, max_x):
                        if p[x][y1]=='X':
                            flag = True
                            break
                    if not flag:
                        turn_ans = 0
                        break
        # 결과 삽입                        
        answer.append(turn_ans)
                    
        
    return answer
