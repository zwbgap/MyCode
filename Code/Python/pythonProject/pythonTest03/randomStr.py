"""
问题描述：编写程序，生成多个字符串，将字符串写入文件，同时读取当前文件，并输出统计字符串的个数。
"""
# 导入模块
import collections
import random
import re
import string

x = string.ascii_letters
s = ' '
n = 10000
while n - 1:
    s = s + ''.join(random.choices(x, k=random.randint(4, 10))) + ' '
    n = n - 1
# 写将字符串写入
f = open(r'SSS.txt', 'w')
f.write(s)
f.close


def fun():
    with open(r'SSS.txt', 'r') as fp:
        content = re.split('[,. ]', fp.read())
        print(content)
        b = collections.Counter(content)  # 计算可迭代序列中各个元素的数量
        print(b)
    with open(r'word2.txt', 'w') as result_file:
        for key, value in b.items():
            result_file.write(key + ':' + str(value) + '\n')
    # 字符串替换
    list1 = s.replace(',', ' ')
    list2 = list1.replace('.', ' ')
    print(list2)
    # 字符串截取
    list3 = list2.split(' ')
    print(list3)
    # 创建空字典
    d = {}
    # 遍历列表
    for i in list3:
        ss = d.get(i)
        if ss is None:
            d[i] = 1
        else:
            d[i] += 1
    print(d)
    # 将字典的值变为列表进行排序
    d1 = sorted(d.items(), key=lambda x: x[1], reverse=True)
    print(d1)


fun()
