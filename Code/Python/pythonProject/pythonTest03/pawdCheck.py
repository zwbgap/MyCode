"""
编写程序以检查用户输入的密码的有效性。
检查密码的标准为：
1    [a-z]之间至少有    1 个字母
2    [0-9]之间至少有    1 个数字
3    [A-Z]之间至少有  1 个字母
4    [$＃@]中至少有    1 个字符
5    最短交易密码长度：6
6)   交易密码的最大长度：12
问题描述：程序接受一系列逗号分隔的密码，进行检查。再输出符合条件
的密码，每个密码用逗号分隔。
"""
import re
import string


def Check_Password(password):
    if len(password) < 6 or len(password) > 12:
        return "密码长度不符合6到12位"

    flag = [False] * 4  # flag函数起到标记标识的作用，有四个标记
    for ch in password:
        if ch in string.ascii_lowercase:  # 检查是否有小写
            flag[0] = True
        if ch in string.ascii_uppercase:  # 检查是否有大写
            flag[1] = True
        if ch in string.digits:  # 检查是否包含数字
            flag[2] = True
        if ch in '$#@':  # 检查是否包含特殊字符串
            flag[3] = True

    if flag.count(True) == 4:  # 检查四个标记是否都正确
        return password
    return "格式不对"


str1 = input("请输入密码，逗号分隔\n")
alist = str1.split(",")
for pwd in alist:
    print(Check_Password(pwd))
