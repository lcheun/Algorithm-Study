import sys
def solution(n, times):
    answer = sys.maxsize
    
    times.sort()
    
    left = 0
    right = n*times[-1]
    
    while left<=right:
        mid = (left+right)//2
        cnt = 0
        
        for t in times:
            cnt += (mid//t)
        
        # 심사 가능한 사람이 n명보다 적은 경우
        if cnt < n:
            left = mid+1
        # n명보다 크거나 같은 경우
        else:
            right = mid-1
            answer = min(mid, answer)
        
    return answer
