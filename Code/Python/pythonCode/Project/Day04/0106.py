x = 1
def reverse(x):
    ans = 0
    y = abs(x)
    while y!=0:
        pop = y%10
        y = y//10
        ans = ans*10 + pop
    if ans>pow(2,31) or ans<pow(-2,31):
        return 0
    if x>=0:
        return ans
    else:
        return -ans
while(x):
    x = int(input("Please enter your  number: "))
    print(reverse(x))