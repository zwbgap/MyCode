#  判断回文 "abcba"
str1 = list(input("请输入："))
#  str2 = "".join(str1)
str2 = str1
str1.reverse()
#  s = "".join(str1)
if str2 == str1:
    print("True")
else:
    print("False")

# print(str1)
# print(s)
# print(str2)
# if str1 == list(reversed(str1)):
#     print("True")
# else:
#     print("False")
