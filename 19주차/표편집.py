# 링크드 리스트
# 삼성 22 하반기 기출과 매우 유사하다

# remove : 삭제 항목
# prev, post = 이전 항목, 이후 항목

import sys
def solution(n, k, cmd):
    answer = ''
    
    ans_arr = ['O' for _ in range(n)]
    
    remove = []
    prev = [i-1 for i in range(0, n)] # 0~n-1까지
    post = [i+1 for i in range(0, n)]
    
    INF = sys.maxsize # 아무것도 없음 = 가장앞 or 가장 뒤
    prev[0] = INF
    post[-1] = INF

    for c in cmd:
        if len(c)>1:
            # type = c[0], num = c[2] 이렇게 해서 테케 겁나 틀렸었당 ^^........ㅎ
            type, num = c.split(' ')
            if type=='U':
                for _ in range(int(num)):
                    if prev[k] != INF:
                        k = prev[k]
                    else:
                        break
            if type=='D':
                for _ in range(int(num)):
                    if post[k] != INF:
                        k = post[k]
                    else:
                        break
        else:
            if c=='C':
                if remove and remove[-1] == k:
                    continue
                remove.append(k)
                ans_arr[k] = 'X'
                # 지운 거 앞 뒤 관계 바꿔줌
                before = prev[k]
                after = post[k]
                if before!=INF:
                    post[before] = after
                if after!=INF:
                    prev[after] = before
                    
                if after == INF and before != INF:
                    k = before
                elif after != INF:
                    k = after
                
            else:
                if remove:
                    re = remove.pop()
                    ans_arr[re] = 'O'
                    # 첫째행이 아닌 경우
                    if prev[re]!=INF:
                        before = prev[re]
                        after = post[re]
                        # 마지막 행이 아닌 경우
                        if after != INF:
                            post[before] = re
                            prev[after] = re
                        else:
                            post[before] = re
                    else:
                        after = post[re]
                        if after != INF:
                            prev[after] = re
                    
                        
    answer = ''.join(ans_arr)
    
    return answer
