import json
from functools import cmp_to_key

n = int(input())
raw_books = json.loads(input())
_book = {}
for raw_book in raw_books['publications']:
    _book[raw_book['publicationNumber']] = raw_book
    _book[raw_book['publicationNumber']]['cited'] = 0

while True:
    ss = ''
    try:
        ss = input()
    except EOFError:
        break
    s = json.loads(ss)
    for cited in s['paperCitations']['ieee']:
        if cited['publicationNumber'] in _book and (cited['year'] == '2017' or cited['year'] == '2018'):
            _book[cited['publicationNumber']]['cited'] += 1

for num in _book:
    articles = 0
    for articleCount in _book[num]['articleCounts']:
        articles += int(articleCount['articleCount'])
    _book[num]['if'] = _book[num]['cited'] / articles

books = []
for num in _book:
    books.append(_book[num])


def compare(a, b):
    if a['if'] == b['if']:
        if a['publicationTitle'] == b['publicationTitle']:
            return 0
        else:
            return 1 if a['publicationTitle'] < b['publicationTitle'] else -1
    else:
        return 1 if a['if'] > b['if'] else -1


books = sorted(books, key=cmp_to_key(compare), reverse=True)

for book in books:
    print('{}: {:.2f}'.format(book['publicationTitle'], book['if']))
