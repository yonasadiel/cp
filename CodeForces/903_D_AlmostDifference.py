pre = 0
ans = 0
n = int(input())
ain = input()
arr = ain.split(" ")
m = {}

for i in range(n):
  a = int(arr[i])
  ans += i*a - pre

  if (a-1 in m and m[a-1] > 0):
    ans -= m[a-1]
  if (a+1 in m and m[a+1] > 0):
    ans -= m[a+1] * -1

  pre += a
  if (a in m):
    m[a] += 1
  else:
    m[a] = 1

print(ans)