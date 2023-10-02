# 列表推导式生成100-200之间的素数
print("100~200之间的素数： ")
lit = [i for i in range(101,200) if 0 not in [i % j for j in range(2, int(i**0.5+1))]]
print("列表推导式: ",end='')
for item in lit:
    print(item,end=" ")
print()

# for 循环生成100-200之间素数
print("For 循环  : ",end="")
for i in range(101,200):
    for j in range(2, int(i**0.5+ 1)):
        if i % j == 0:
            break
    else:
        print(i,end=" ")