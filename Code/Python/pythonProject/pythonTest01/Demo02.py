import random
import time
systemNum = random.randint(1, 101)
# 猜数字的次数
count = 5
print(f'You have {count} chances!')

while count:
    count = count - 1
    inputNum = input("Please input the number：")
    if systemNum > int(inputNum):
        print("too small!")
        print(f'You have {count} chances!')
    elif systemNum < int(inputNum):
        print("too large!")
        print(f'You have {count} chances!')
    else:
        print("right")
        break
time.sleep(1)
if count == 0:
    print(f'GAME IS OVER!\nThe right answer is: {systemNum}')
