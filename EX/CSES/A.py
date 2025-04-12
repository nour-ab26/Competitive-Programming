def smallest_word(n):
    if n % 26 == 0:
        return 'z' * (n // 26)
    else:
        chars = ['a'] * ((n // 26) + 1)
        chars[-1] = chr(ord('a') + (n % 26) - 1)
        return ''.join(chars)

# Input
t = int(input().strip())

# Process each test case
for i in range(t):
    n = int(input().strip())
    print(smallest_word(n))
