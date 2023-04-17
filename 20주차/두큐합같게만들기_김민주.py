def solution(queue1, queue2):
    answer = 0
    sum1 = sum(queue1)
    sum2 = sum(queue2)
    q_sum = sum1+sum2
    
    if q_sum%2!=0:
        return -1
    
    make = q_sum//2
    
    qq = queue1+queue2
    
    left = 0
    right = 0
    sum_ = qq[0]
    while left<len(qq) and right<len(qq):
        if sum_<make:
            right += 1
            if right>=len(qq):
                break
            sum_ += qq[right]
        elif sum_ > make:
            sum_ -= qq[left]
            left += 1
        else:
            if right>=len(queue1)-1:
                break
            else:
                sum_ -= qq[left]
                left += 1
                
            
   # print(sum_, left, right)
    # 만들었다!    
    if sum_==make:
        answer += left
        answer += right-(len(queue1)-1)
    else:
        return -1
            
            
    return answer
