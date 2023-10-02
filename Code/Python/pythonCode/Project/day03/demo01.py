from itertools import cycle
# from unittest import result
# 进行简单的异或算法对字符串进行加密和解密
def crypt(source, key):
    result = ""
    temp = cycle(key)
    for ch in source:
        result += chr(ord(ch)^ord(next(temp)))
    return result

def crypt1(source, key):
    func = lambda x, y : chr(ord(x)^ord(y))
    return "".join(map(func, source,cycle(key)))
while True:

    source = input("Please input a str:")
    # source = "huft is a good 211 university."
    key = "Dong Fuguo"

    print(f'before :{source}')
    encrypted = crypt(source, key)
    print(f'After Encrypted:{encrypted}')
    decrypted = crypt(encrypted, key)
    print(f'After Decryptrd:{decrypted}')

# print(f'before :{source}')
# encrypted = crypt1(source, key)
# print(f'After Encrypted:{encrypted}')
# decrypted = crypt1(encrypted, key)
# print(f'After Decryptrd:{decrypted}')


