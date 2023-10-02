import random

systemNum = random.randint(1, 101)
inputNum = input("Please input the number：")

if systemNum > int(inputNum):
    print("too small!")
    print(f'GAME IS OVER!\n The right answer is: {systemNum}')
elif systemNum < int(inputNum):
    print("too large!")
    print(f'GAME IS OVER!\nThe right answer is: {systemNum}')
else:
    print("right")

