"""
보고 나서 이게 투포인터 문제임은 알았으나, 정확히 어떻게 구현할지 헷갈려서 답 확인
1. 일단은 오른쪽으로 보는 부분을 늘려가면서 보석을 다 담도록 함
2. 다 담았으면 최소범위를 구하기 위해 left를 하나씩 줄여보는것
3. 다만, 보석 종류를 다 담았던 순간에 무조건 answer에 저장해놔야함

※ dict value값으로 지금까지 마주친 해당 보석 수를 저장하는 방식
- 만약 left를 줄이다가 0이 되면 dict에서 delete하는 방식으로 해야한다는것을 깨달음
"""
import sys

input = sys.stdin.readline


def solution(gems):
    answer = [0, len(gems)]  # 일단 처음부터 끝을 정답으로 기입
    num = len(set(gems))  # for문 돌면서 map에 넣을 생각이었는데 이런 한줄짜리가 있었음
    left, right = 0, 0
    gem_dict = {gems[0]: 1}  # 딕셔너리 초기화 방법

    while left < len(gems) and right < len(gems):
        if len(gem_dict) == num:
            if right - left < answer[1] - answer[0]:
                answer = [left, right]
            else:
                gem_dict[gems[left]] -= 1
                if gem_dict[gems[left]] == 0:
                    del gem_dict[gems[left]]
                left += 1

        else:
            right += 1
            if right == len(gems):
                break

            if gems[right] in gem_dict:
                gem_dict[gems[right]] += 1
            else:
                gem_dict[gems[right]] = 1

    return [answer[0] + 1, answer[1] + 1]  # 문제에서 진열대는 idx 1부터 시작


if __name__ == "__main__":
    gems = list(map(str, input().split()))
    output = solution(gems)
    print(output)
