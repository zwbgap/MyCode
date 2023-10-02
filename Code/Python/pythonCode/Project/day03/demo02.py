# 运行失败，错误未解决
import random
import re
import string
from xml import dom 
# 常用汉字Unicode编码表
StringBase = '\u7684\u4e00\u662f\u4e86\u6211\u4e0d\u4eba\u5728\u4ed6'\
    '\u6709\u8fd9\u4e2a\u4e0a\u4eec\u6765\u5230\u65f6\u5927\u5730\u4e3a'\
    '\u5b50\u4e2d\u4f60\u8bf4\u751f\u56fd\u5e74\u7740\u5c31\u90a3\u548c'

def getEmail():
    # 常见域名后缀
    suffix = ['.com','.org','.net','.cn']
    characters = string.ascii_letters + string.digits + "_"
    username = "".join(random.choices(characters,k = random.randrange(6.12)))
    domain = "".join(random.choices(characters, k = random.randrange(3,7)))
    return username+'@'+domain+random.choice(suffix)

def getTelNo():
    return "".join(random.choices(string.digits, k=11))

def getNameOrAddress(flag):
    # flag = 1 返回随机姓名， flag = 0 返回随机地址
    if flag == 1:
        # 姓名大多2-5个汉字
        rangestart, rangeend = 2, 5
    elif flag == 0:
        # 假设地址为10-30个汉字
        rangestart, rangeend = 10, 31
    else:
        print("Flag must be 1 or 0")
        return ""
    return "".join(random.choices(StringBase,
               k = random.randrange(rangestart,rangeend)))

def getSex():
    return random.choices(('男女'))

def getAge():
    return str(random.randint(18,100))

def main():
    print('Name,Sex,Age,TelNo,Address,Email') 
    # 生成200个人的随机信息
    for i in range(200):
        name = getNameOrAddress(1)
        sex = getSex()
        age = getAge()
        tel = getTelNo()
        address = getNameOrAddress(0)
        email = getEmail()
        line = ",".join([name,sex,age,tel,address,email])
        print(line)

if __name__ == '__main__':
    main()


