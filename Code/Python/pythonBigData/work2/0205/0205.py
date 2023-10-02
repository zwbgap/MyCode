"""
定义函数，函数的参数是一个整数，返回值是一个三元素的元组，元组分别是整数值、整数的平方值、整数的立方值。
"""

from random import randint


def fun(*n):
    for i in n:
        print((i, i ** 2, i ** 3))


if __name__ == '__main__':
    list1 = [randint(0, 200) for i in range(10)]
    fun(*list1)

# def fun(n):
#     ls = [n, n ** 2, n ** 3]
#     return tuple(ls)
#
#
# if __name__ == "__main__":
#     ls = []
#     for i in range(11):
#         number = randint(0, 201)
#         ls.append(number)
#     for number in ls:
#         print(fun(number))
