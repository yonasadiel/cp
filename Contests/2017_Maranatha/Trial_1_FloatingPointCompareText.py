import math

n = int(input())
for i in range(0,n):
    x = 0.01
    x = float(input())
    if (math.isnan(x)):
        print('NaN')
    elif (x == 0):
        print('Inf')
    else:
        x = x*1.0
        print(1/x)
print('\n')
