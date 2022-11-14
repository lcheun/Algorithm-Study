# abacaca
# abacacaba

S = input()


def check(string):
    start = 0
    end = len(string)-1
    while start <= end:
        if string[start]!=string[end]:
            return False

        start += 1
        end -= 1

    return True


index = 0
temp = S
while True:
    if check(temp):
        print(len(temp))
        break

    temp_index = index
    temp = S
    while temp_index>=0:
        temp += S[temp_index]
        temp_index-=1

    index+=1

######### 모범답안

for i in range(len(S)):
    # S[i:] : i부터 시작한 문자열
    # S[i:][::-1] : i부터 시작한 문자열을 거꾸로 읽는 거
    if S[i:] == S[i:][::-1]:
        print(len(S)+i)
        break