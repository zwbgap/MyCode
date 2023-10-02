#  计算斐波那契数列的第n项值
def fib1(n):
    if not isinstance(n, int) or n < 1:
        return None
    a, b, i = 0, 1, 1
    while i < n:
        a, b = b, a + b
        i += 1
    print(b)

def fib(n):
    """计算斐波那契数列中小于n的所有值"""
    a, b = 1, 1  # a,b赋值1
    while a < n:
        print(a, end=',')
        a, b = b, a + b
    print()


n = int(input("斐波那契数："))
print(f'第{n}项:')
fib1(n)
print(f'前{n}项：')
fib(n)