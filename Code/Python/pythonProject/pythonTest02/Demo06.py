Str = input("请输入一串字符:")
result = {}  # 定义一个空字典
for i in Str:  # 遍历输入的字符串，以键值对的方式存储在字典中
    result[i] = Str.count(i)
for key in result:  # 遍历字典，格式化输出结果
    print(f'"{key}":{result[key]}次')

