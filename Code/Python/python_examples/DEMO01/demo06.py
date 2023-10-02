# a = [[[[None] * 2] * 3] * 4] * 5
# a[0][0][0][0] = 5
# print(a)
#
# a = [21654, 3654, 236, 21, 4]
# print(sorted(a, key=lambda x: (-len(str(x))), reverse=True))
#
# # g = (i ** 2 for i in range(10))
# # print(g)
# # print(tuple(g))
# # print(list(g))
# g = ((i + 2) ** 2 for i in range(10))
# # print(g.__next__())
# # print(g.__next__())
#
# print(next(g))
# print(next(g))
# # print(tuple(g))
# for item in g:
#     print(item, end=" ")

# keys = ['a', 'b', 'c', 'd', 'e', 'f']
# values = [1, 2, 3, 4, 5, 6]
# dictionary = dict(zip(keys, values))
# print(dictionary)
#
# adict = dict.fromkeys(['a', 'b', 'c'])
# print(adict)
# a = dict(one=1, two=2, three=3)
# print(a)
# b = {'one': 1, 'two': 2, 'three': 3}
# c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
# d = dict([('two', 2), ('one', 1), ('three', 3)])
# e = dict({'three': 3, 'one': 1, 'two': 2})
# f = dict({'one': 1, 'three': 3}, two=2)
# print(a == b == c == d == e == f)
# print(a['one'])
# print(a.items())
# print(a)

# import random
# import string
# x = string.digits
# y = random.choices(x, k=15)
# print(y)
# z = ''.join(y)
# d = dict()
# for ch in z:
#     d[ch] = d.get(ch, 0) + 1
# print(d)

# s = set((1, 2, 3))
# t = set((2, 3, 4))
# print(s.intersection_update(t))
# print(s)
# print(s.intersection(t))

# import queue
# q = queue.Queue()
# q.put(0)
# q.put(1)
# q.put(2)
# print(q.queue)
# print(q.get())
# print(q.queue)

# a = "a,,,bb,,ccc".split(',')
# print(a)
# print(id(b'b'))
# print(id('b'))
#
# import string
# a = string.digits + string.ascii_letters + string.punctuation
# print(a)
# print(str.isalnum('foo'))
# import random
#
#
# def demo(*para):
#     avg = sum(para) / len(para)
#     g = [i for i in para if i > avg]
#     return (avg,) + tuple(g)
#
#
# print(demo(1, 2, 3, 4))
#
# x = [[random.randint(0, 10) for i in range(5)] for j in range(5)]
# print(x)
#
# a = ([random.randint(0, 10) for i in range(5)] for j in range(5))
# for i in a:
#     print(i)
#
#
# def demo(a, n):
#     assert type(a) == int and 0 <= a < 10, 'a must be integer between 0 and 9'
#     a = str(a)
#     return sum(eval(a * i) for i in range(1, n + 1))
#
#
# print(demo(5, 3))
#
# print(eval('5' * 2))


# def demo01(n):
#     a, b, c = 1, 2, 4
#     for i in range(n - 3):
#         c, b, a = a + b + c, c, b
#         return c
#
#
# print(demo01(15))
#
#
# def demo02(n):
#     first3 = {1: 1, 2: 2, 3: 4}
#     for n in first3.keys():
#         return first3[n]
#     else:
#         return demo02(n - 1) + demo02(n - 2) + demo02(n - 3)
#
#
# print(demo02(15))
#
#
# def demo(**p):
#     for item in p.items():
#         print(item)
#
#
# demo(x=1, y=2, z=3)
# a = dict(x=1, y=1, z=1)
# print(a)
# for i in a.items():
#     print(i)
#
# x = [1, 2, 3, 4, 5]
# print(x[len(x) - 3:])
# import random
#
# list_a = [random.randint(1, 20) for i in
#           range(50)]  # 使用random里面的randint(1, 20), 表示在1-20中生成随机数， for i in range(50)随机生成50个元素。
# set_b = set(list_a)  # 创建集合set_b， 因为集合可以去除list_a中重复的数字， 只保留一个。
# for i in set_b:
#     print(i, ':', list_a.count(i),":", list_a.count(i)/50)  # 遍历集合set_b中每个元素，输出个数(list_a.count计算该元素在列表list_a中出现的次数)。
#
# x = [lambda x: 2, lambda x=10: 3 * x]
# for i in x:
#     print(i)
# print(round(3.75468))
# x = [1, 2, 3, 4]
# del x[1]
# print(x)
#
# g = ((i + 2) ** 2 for i in range(10))  # 重新创建生成器对象
# print(g.__next__())  # 使用生成器对象的__next__()方法获取元素
# print(next(g))

print(0 < True < 4)

alist = [1, 3, 4, 8, 9, 7]
sorted(alist, reverse=True)
print(alist)

ls = [1, 102, -4, 8, 55]
print(sorted(ls, key=lambda x: str(abs(x))))

str1 = "姓名: %s\t年龄:%d\t"
print(str1 % ("张扬", 25))

a, b, c, d, e, f = 'python'
print(b)

# print(bool("Hello, world!"))
# a = (3,) + tuple(ls)[:]
# print(a)
# ls = tuple(ls)
# print(ls)
# tup = ls[:3] + ls[4:]
# print(tup)
# print(ls[-1:0:-1])
# print(int(True))
# print(int(False))

import numpy as np

arr = np.arange(1, 10)
print(arr)
