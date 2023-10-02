import re

# sr = input('请输入一段英文：')
# print(re.findall(r'\b[a-zA-Z]{3}\b', sr))
words = input("Input the words:")
l = re.split('[\.]+', words)  # 使用空格分隔词语，得到各个单词
print(l)
i = 0  # 这里我设置的是计数器
for i in l:
    if len(i) == 3:  # 如果单词的长度为3  输出
        print(i, end=" ")
