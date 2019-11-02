import json


n = int(raw_input())

result = dict()

for i in range(n):
    s = raw_input()
    d = json.loads(s)
    authors = d['authors']['authors']
    for author in authors:
        if result.get(author['full_name'], None) is None:
            result[author['full_name']] = []
        result[author['full_name']].append(d['citing_paper_count'])

ans = []
for key, value in result.iteritems():
    h = 0
    value.sort(reverse=True)
    for i, x in enumerate(value):
        if x >= i + 1:
            h = i + 1
    ans.append((-h, key))

ans.sort()
for a in ans:
    print '%s %d' % (a[1], -a[0])
