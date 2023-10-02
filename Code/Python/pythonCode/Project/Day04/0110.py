import string
# 第一种
# d = dict()
# for i in ascii_letters:
#     d[i] = ord(i)                                                                                                                                                                                                                                                vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
# print(d)
d = dict() 
# d = {i:ord(i) for i in ascii_letters}
print({i:ord(i) for i in string.ascii_letters})
# 第二种
print()
print(dict(zip(string.ascii_letters,[ord(ch) for ch in string.ascii_letters] )))
