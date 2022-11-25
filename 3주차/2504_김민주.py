bracket = input()
length = len(bracket)
stack = []
tmp = 1 #지금 계산하고 있는 부분의 계산 값
answer = 0 #전체 계산 값

# stack 이용해서 쌍 비교, ( 나오면 2곱하고 [ 나오면 3곱하는 거 까지는 ok
# 곱셈과 덧셈 구분이 헷갈렸음
for i in range(length):
    b = bracket[i]
    if b == '(':
        tmp*=2
        stack.append(b)
    elif b =='[':
        tmp*=3
        stack.append(b)
    elif b == ')':
        if not stack or stack[-1]=='[':
            answer = 0
            break
        if bracket[i-1] == '(':
            answer += tmp
        tmp //= 2 # 2*(2+3) 이라면 2*2 + 2*3과 같기 때문에 2*2'에서 2'로 나눠 2만 남긴다 . 그럼 다음에 3이 나왔을 때 2*3이 되고 answer에 2*2+2*3이 곱해짐
        stack.pop()
    else:
        if not stack or stack[-1] == '(':
            answer = 0
            break
        if bracket[i-1] == '[':
            answer += tmp

        tmp//=3
        stack.pop()

if stack:
    answer = 0
print(answer)


