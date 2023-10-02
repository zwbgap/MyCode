import math
#  输入一个大于 2 的自然数，然后输出小于该数字的所有素数组成的列表。
n = eval(input("Please input the Number:"))
s = []
for j in range(2,n+1):
    for i in range(2, int(math.sqrt(j)) + 1):
        if j % i == 0:
            break;
    else:
        s.append(j)

print(s)
