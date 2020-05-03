from math import gcd

t = int(input())

for tc in range(t):
    n, li = map(int, input().split())
    c = list(map(int, input().split()))
    d = [0 for i in range(len(c) + 1)]
    start = 0
    for i in range(len(c) - 1):
        if (c[i] != c[i + 1]):
            d[i + 1] = gcd(c[i], c[i + 1])
            start = i + 1
            break
    for i in range(start - 1, -1, -1):
        d[i] = c[i] // d[i + 1]
    for i in range(start + 1, len(d)):
        d[i] = c[i - 1] // d[i - 1]

    e = list(set(d.copy()))
    e.sort()

    print('Case #{}: {}'.format(tc + 1, ''.join([chr(e.index(cc) + ord('A')) for cc in d])))
