def translate(s):
    if (s[0] == 'x'):
        return '0'
    if (s[0] == 'p'):
        return '1'
    if (s[0] == 'y' and s[1] == 'e'):
        return '2'
    if (s[0] == 'y'):
        return '3'
    if (s[0] == 'g' and s[1] == 'p'):
        return '4'
    if (s[0] == 'g'):
        return '5'
    if (s[0] == 'd' and s[1] == 'o'):
        return '6'
    if (s[0] == 'd'):
        return '7'
    if (s[0] == 'r'):
        return '8'
    if (s[0] == 'm'):
        return '9'


n = int(raw_input())
ans = 1
for i in range(n):
    s = raw_input().strip().split()
    r = ""
    for j in range(len(s)):
        r += translate(s[j])
    x = int(r, 16)
    ans *= x

print(ans)
