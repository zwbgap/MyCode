# Lambda
students = [
    {'name': 'TOM', 'age': 20},
    {'name': 'ROSE', 'age': 19},
    {'name': 'Jack', 'age': 22}
]

# 按name值升序排列
students.sort(key=lambda x: x['name'])
print(students)

# 按name值降序排列
students.sort(key=lambda x: x['name'], reverse=True)
print(students)

# 按age值升序排列
students.sort(key=lambda x: x['age'])
print(students)

# 函数式编程
# 方法一
# def add_num(a, b):
#     return abs(a) + abs(b)

# result = add_num(-1, 2)
# print(result)  # 3

#方法二
def sum_num(a, b, f):
    return f(a) + f(b)

result = sum_num(-1, 2, abs)
print(result)  # 3

list1 = [1, 2, 3, 4, 5]


def func(x):
    return x ** 2


result = map(func, list1)

print(result)  # <map object at 0x0000013769653198>
print(list(result))  # [1, 4, 9, 16, 25]

import functools

list1 = [1, 2, 3, 4, 5]
def func(a, b):
    return a * b

result = functools.reduce(func, list1)

print(result)  # 15


list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
def func(x):
    return x % 2 == 0


result = filter(func, list1)

print(result)  # <filter object at 0x0000017AF9DC3198>
print(list(result))  # [2, 4, 6, 8, 10]
