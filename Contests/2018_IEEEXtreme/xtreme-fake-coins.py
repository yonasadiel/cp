def evaluate(op, co1, co2):
    res = 0
    for x in op:
        if (ord(x) - ord('A') == co1) or (ord(x) - ord('A') == co2):
            res += 1
        else:
            res += 2
    return res


def stringi(co1, co2):
    if (co1 > co2):
        co1, co2 = co2, co1
    return '%s%s' % (chr(co1 + ord('A')), chr(co2 + ord('A')))


N, M = raw_input().strip().split(',')
N = int(N)
M = int(M)

ops = []
for i in range(M):
    ops.append(raw_input().strip().split('-'))

result = dict()

for i in range(N):
    for j in range(i + 1, N):
        res = ''
        for op in ops:
            le = evaluate(op[0], i, j)
            ri = evaluate(op[1], i, j)

            if (le < ri):
                res += '<'
            elif (le == ri):
                res += '='
            else:
                res += '>'
        if result.get(res, None) is None:
            result[res] = []
        result[res].append((i, j))

ans = []

for key, value in result.iteritems():
    for i in range(len(value)):
        for j in range(i + 1, len(value)):
            ans.append('%s=%s' % (stringi(value[i][0], value[i][1]), stringi(value[j][0], value[j][1])))

ans.sort()

for anss in ans:
    print(anss)
