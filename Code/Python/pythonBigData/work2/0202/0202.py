"""
建立一个10个姓名的列表,和十个学号的列表。
通过zip函数生成zip对象并实现以学号为键姓名为值的字典。
"""

import random

if __name__ == "__main__":
    numbers = []
    name = ["曹一", "鲁二", "张三", "李四", "王五", "赵六", "陈七", "钱八", "孙九", "周十"]
    for i in range(10):
        number = random.randrange(10000000, 99999999, 1)
        numbers.append(number)
    dic = dict(zip(numbers, name))

    print(dic)

