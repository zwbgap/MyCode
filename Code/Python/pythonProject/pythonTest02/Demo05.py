import random

n, m = 20, 40
print(tuple(filter(lambda x: x % 2 == 1 and x <= m, random.sample(range(50), n))))
# sample(a,b)从序列a中任取b个元素
print(tuple((x for x in random.sample(range(50), n) if x % 2 == 1 and x <= m)))
