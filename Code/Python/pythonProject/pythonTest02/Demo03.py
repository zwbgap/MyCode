import string
import random

ch = string.digits + string.ascii_letters  # 数字和字母组成的字符串
n, m = 10, 10
res = [[''.join(random.sample(ch, random.randint(1, m)))] for i in range(n)]
print(sorted(res, key=lambda x: len(x[0]), reverse=True))