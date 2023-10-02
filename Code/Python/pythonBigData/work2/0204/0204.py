"""
随机产生1000个10000到30000的正整数列表,然后去掉列表中额重复元素,然后按升序排序
"""
from random import randint
# from collections import Counter
list1 = [randint(10, 50) for i in range(20)]
# print(Counter(list1))
print(f'去重前    :{list1}')
print(f'去重排序后:{sorted(list(set(list1)))}')