N = int(input())

arr = list(input() for _ in range(N))
first_len = len(arr[0])

answer = 0

def minus(word1, word2):
    for i in range(len(word2)):
        if sorted(word2[:i]+word2[i+1:]) == sorted(word1):
            return True

    return False

def replace(word1, word2):
    for i in word1:
        if minus(word1, word2+i):
            return True

    return False

def plus(word1, word2):
    for i in range(len(word1)):
        if sorted(word2[:i]+word1[i]+word2[i:]) == sorted(word1):
            return True

    return False




for i in range(1, len(arr)):
    if len(arr[i]) == first_len:
        if sorted(arr[i])==sorted(arr[0]):
            answer += 1
        elif replace(arr[0], arr[i]):
            answer += 1
    elif len(arr[i]) == first_len-1:
        if plus(arr[0], arr[i]):
            answer += 1
    elif len(arr[i]) == first_len+1:
        if minus(arr[0], arr[i]):
            answer += 1

print(answer)
