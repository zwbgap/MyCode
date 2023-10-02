# #!/usr/bin/python3

# # 打开一个文件
# f = open("D:\pythonCode\Project\Day01\\foot.txt", "w")
# f.write( "Python 是一个非常好的语言。\n是的,的确非常好!!\n" )
# f.write("文件的读写测试")

# # 文件的读取
# f = open("D:\pythonCode\Project\Day01\\foot.txt", "r")
# str = f.readlines()
# print(str)

# # 关闭打开的文件
# f.close()

# f = open("D:\pythonCode\Project\Day01\\foot.txt", "r")
# for line in f:
#     print(line, end = ",")
# f.close()
# f = open("D:\pythonCode\Project\Day01\\foot.txt", "w")

# num = f.write( "Python 是一个非常好的语言。\n是的,的确非常好!!\n" )
# num += f.write("文件的再次读写测试")
# print()
# print(num)
# f.close()

f = open("D:/pythonCode/Project/Day01//foot.txt", "w")
value = ('www.runoob.com', 14)
s = str(value)
f.write(s)
# 关闭打开的文件
f.close()