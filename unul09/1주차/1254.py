def is_palindrome(word):
    return word == word[::-1]


word = input()

for i in range(len(word), 0, -1):
    if is_palindrome(word[-i:]):
        print(2*len(word) - i)
        break