list1 = []
def isGDBH(num):
    for i in range(2,100):
        for j in range(2,int(i**0.5+1)):
            if i % j == 0:
                break
        else:
            list1.append(i)

    print(list1)
    list2 = []
    for i in list1:
        for j in list1[list1.index(i)::]:
             if i + j == num:
                list2.append((i, j, num))
    print(f'哥德巴赫猜想(a+b=n)：{list2}')

num = int(input("Please input a even number of 6 ~ 200: "))
isGDBH(num)



