import random

# 随机产生包含 n 个整数的列表，返回一个元组，
# 其中第一个元素为所有参数的平均值，其他元素为所有参数中大于平均值的整数。

# 1
def list_average(n):
    list1 = random.sample(range(101), n)
    print(list1)
    list_avg = sum(list1) / n
    list2 = [list_avg]
    for i in list1:
        if i > list_avg:
            list2.append(i)
    print(tuple(list2))


list_average(10)


#   2
def average1(*para):
    avg = sum(para) / len(para)
    g = [i for i in para if i > avg]
    return (avg,) + tuple(g)


list_demo = (random.sample(range(101), 10))
print(average1(*list_demo))
