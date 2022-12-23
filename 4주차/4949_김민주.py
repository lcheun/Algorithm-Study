while True:
    string = input()
    if string=='.':
        break

    stack = []
    flag = True
    for c in string:
        if c=='[' or c=='(':
            stack.append(c)
        elif c==')':
            if not stack or stack[-1] != '(':
                flag = False
                break
            else:
                stack.pop()
        elif c==']':
            if not stack or stack[-1] != '[':
                flag = False
                break
            else:
                stack.pop()

    if flag and not stack:
        print('yes')
    else:
        print('no')

