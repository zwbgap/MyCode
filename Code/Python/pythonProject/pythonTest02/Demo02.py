# 方法一
# setA = eval(input('请输入一个集合：'))
# setB = eval(input('再输入一个集合：'))
# # print('交集：', setA & setB)
# # print('并集：', setA | setB)
# # print('setA-setB：', setA - setB)
# print(f'交集{setA & setB}\n并集{setA | setB}\n差集{setA - setB}')
#

# 方法二

def test_set():
    set_A = eval(input("请输入一个集合："))
    set_B = eval(input("再输入一个集合："))
    print("交集:", end="")
    for i in set_A:
        if i in set_B:
            print(" ", end="")
            print(i, end="")
    print()
    print("并集:", end="")
    for i in set_A:
        print(" ", end="")
        print(i, end="")
    for i in set_B:
        if i not in set_A:
            print(" ", end="")
            print(i, end="")
    print()
    print("差集:", end="")
    for i in set_A:
        if i not in set_B:
            print(" ", end="")
            print(i, end="")


test_set()
