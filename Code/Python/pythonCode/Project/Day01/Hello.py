print('Hello World!')
# 单行注释
# 'one'
'''
多行注释
多行注释
'''
# 求和
i = 2
sum1 = 0
while i <= 100:
    sum1 += i
    i += 2
print("1-100之间的和是：%d" % sum1)

i = 1
my_sum = 0
while i <= 100:
    if i % 2 == 0:
        my_sum += i
    i += 1
print("1-100之间的和是：%d" % my_sum)

for i in "Hello World!":
    if i == ' ':
        continue
    print(i, end=" ")
print()

for i in range(10+1):
    print(i, end=" ")
print()

for i in range(2, 12):
    print(i, end=" ")
print()

for i in range(2, 20, 4):
    print(i, end=" ")
print()
