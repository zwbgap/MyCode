""" 编写程序，生成一个整型列表，输出包含原列表中所有元素的新列表、包含
    原列表中所有元素的逆序列表，以及输出具有偶数位置的元素列表。
    """
import random

x = []
x1 = []
for i in range(20):
    x.append(random.randint(0, 101))
print(f'随机生成的整形列表为：{x}')
x.reverse()
print(f'随机整型列表逆序后为：{x}')
x.reverse()
for i in range(0, 20, 2):
    x1.append(x[i])

print(f'偶数位置的元素列表为：{x1}')
