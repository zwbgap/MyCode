# 匹配手机
import re


def phone_number_check(test_phone_Str):
    if len(test_phone_Str) != 11 or test_phone_Str is None or not test_phone_Str[0:10].isdigit():
        print("Phone number is wrong!")
    pat = '\d{1}[34578]{1}\d{9}'
    res = re.match(pat, test_phone_Str)
    if res:
        print("Phone number is right!")
    else:
        print("Phone number is wrong!")

def id_check(id):
    if id is None:
        return False
    if len(id) != 18:
        return False
    if not (id[0:17].isdigit()):
        return False

    if int(id[6:10]) % 4 == 0 or (int(id[6:10]) % 100 == 0 and int(id[6:10]) % 4 == 0):
        # 出生日期闰年时合法性正则表达式
        birthday = re.compile(
            '[1-9][0-9]{5}(19[0-9]{2}|20[0-9]{2})((01|03|05|07|08|10|12)(0[1-9]|[1-2]              [0-9]|3[0-1])|('
            '04|06|09|11)(0[1-9]|[1-2][0-9]|30)|02(0[1-9]|[1-2][0-9]))[0-9]{3}[0-9Xx]$')
    else:
        # 出生日期平年时合法性正则表达式
        birthday = re.compile(
            '[1-9][0-9]{5}(19[0-9]{2}|20[0-9]{2})((01|03|05|07|08|10|12)(0[1-9]|[1-2]           [0-9]|3[0-1])|('
            '04|06|09|11)(0[1-9]|[1-2][0-9]|30)|02(0[1-9]|1[0-9]|2[0-8]))[0-9]{3}[0-9Xx]$')
    if not (re.match(birthday, id)):
        return False

    mod = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
    jym = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']
    sum = 0
    for i in range(0, 17):
        sum += int(id[i]) * mod[i]
    sum %= 11
    if (jym[sum]) == id[17]:
        return True
    else:
        return False


testStr = ['18456789681', '19456987456',
           '18756365496', '18756365468705', '156-;.,7965421']

for i in testStr:
    phone_number_check(i)

id = ['330702196302260412X', '34052419800101001X', '340524198001010011',
        '3307021963X226041X', '33070219630226041X']
for i in id:
    if id_check(i):
        print("ID is right!")
    else:
        print("ID is wrong!")
