import random

while True:
    user = int(input("请输入您的选择:1(石头) 2(剪刀) 3(布)\n"))

    computer = random.randint(1, 3)

    if user == computer:
        print("平局")
    elif user > 3:
        print("error")
    elif (user == 1 and computer == 2) or (user == 2 and computer == 3) or (user == 3 and computer ==1):
        print("恭喜你，您胜利了")
    else:
        print("您失败了")
    print("游戏结束！")
