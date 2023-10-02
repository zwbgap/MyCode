import random
import string
import collections

# 方法一

x = string.ascii_letters + string.digits
# 字符串x为a-zA-Z0-9
y = "".join([random.choice(x) for i in range(1000)])
# choice用于从多个元素中随机选择一个
z_dict = dict()  # 创建空字典
for ch in y:
    z_dict[ch] = z_dict.get(ch, 0) + 1
    # 统计次数

# 打印显示
for k, v in sorted(z_dict.items()):
    print(k,":",v, end='\t')
print()

#  方法二
# import collections

x = string.ascii_letters + string.digits
y = "".join([random.choice(x) for i in range(1000)])
count = collections.Counter(y)
# print(count)
for k, v in sorted(count.items()):
    print(k, ":", v, end='\t')
print()
# 方法三
# import random
x = string.ascii_letters + string.digits
m_str = "".join(random.choices(x, k=1000))
print("字符串长度", len(m_str))
# set集合去重
m_set = set(m_str)
# 遍历，长度为set集合，键值放入字典中
m_dict = dict()
for i in m_set:
    nums = m_str.count(i)  # 母串中每个字符出现的次数
    m_dict[i] = nums
# sorted(m_dict.items())
# 打印结果
for i in sorted(m_dict.items()):  # items()方法可以返回字典的“键：值”对
    print(i, end='\t')  # end=''表示取消换行
