# 12、查找两个字符串首尾交叉的最大子串长度，
# 连接两个字符串，首尾交叉部分只保留一份。例如，1234 和 2347 连接为 12347
# 要求：程序中使用 lambda 表达式以及函数

def fun_check(str_1, str_2):
    length1 = len(str_1)  # 取两个字符串长度
    length2 = len(str_2)
    length = min(length1, length2)
    k = max(range(0, length + 1), key=lambda i: i if str_1[length1 - i:] == str_2[:i] else False)  # lambda表达式，找出重复数
    print('重复数为：', k)
    return str_1 + str_2[k:]


str1 = input("请输入字符串:")
str2 = input("请输入字符串:")
print(fun_check(str1, str2))
