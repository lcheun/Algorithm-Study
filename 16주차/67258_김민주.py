def solution(gems):
    answer = [0, len(gems)-1]
    dic = {gems[0]:1}
    type = len(set(gems))
    
    left, right = 0, 0
    while left<len(gems) and right<len(gems):
        # 모든 종류 보석 포함
        if len(dic)==type:
            # 길이가 짧은 경우
            if right-left < answer[1]-answer[0]:
                answer = [left, right]
            # 다음 구간 탐색위해 left에 해당하는 dic값 조정 & left += 1
            if dic[gems[left]] == 1:
                del dic[gems[left]]
            else:
                dic[gems[left]] -= 1
            left += 1
        else:
            right += 1
            if right >= len(gems):
                break
            
            dic[gems[right]] = dic.get(gems[right], 0) + 1
            
    answer[0] += 1
    answer[1] += 1
    return answer
            
    
    return answer