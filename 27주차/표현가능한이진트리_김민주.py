def is_tree(s, parent):
    if parent == '0':
        if not all(child=='0' for child in s):
            return False
    if len(s) == 1:
        return True
    center = len(s)//2
    return is_tree(s[:center], s[center]) and is_tree(s[center+1:], s[center])

def solution(numbers):
    answer = []

    
    for num in numbers:
        binary = bin(num)[2:]
        for i in range(51):
            digit = 2**i-1
            if digit >= len(binary):
                break
        binary = '0' * (digit-len(binary))+binary
        tree = is_tree(binary, binary[len(binary)//2])
    
        if tree:
            answer.append(1)
        else:
            answer.append(0)
            
    return answer
