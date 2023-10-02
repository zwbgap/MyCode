# 1. 打开文件
f = open('python.txt', 'w')

# 2.文件写入
for i in range(5):
    f.write('My name is ZhangYang!\t\n')

# 3. 关闭文件
f.close()

f = open('python.txt')
result = f.read()
# result = f.readlines()
print(result)
f.close()

f = open('python.txt')
content = f.readlines()

# ['hello world\n', 'abcdefg\n', 'aaa\n', 'bbb\n', 'ccc']
print(content)

# 关闭文件
f.close()

# readline()
f = open('python.txt')

content = f.readline()
print(f'第一行：{content}')

content = f.readline()
print(f'第二行：{content}')

# 关闭文件
f.close()