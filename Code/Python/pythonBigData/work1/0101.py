# for循环求和
a = int(input('Please enter a number :'))
Sum_for = 0
for i in range(a):
    Sum_for += (i + 1);
print(f'For循环求和(1~{a}): {Sum_for}')


# sum方法求和

print(f'sum函数求和(1~{a}): {sum(item+1 for item in range(a))}')
