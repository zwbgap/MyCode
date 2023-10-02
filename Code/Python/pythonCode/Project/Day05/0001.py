print({index for index, value in enumerate([5,9,8,8,9]) if value == max([5,9,8,8,9])})

x = [4,6,5,6,7]
print([x.index(i) for i in x if i==6])

b = [[5]] * 3
print(b)
b[0][0] = 8
print(b)

c = [8,2,5,1,4,12,45,33,12,32]
print(c[-1:3:-1])
print(c[-1:-3])

print(2 if 2>3 else(3 if 3 > 2 else 2))

print('{1:*>8.3f},{0:$<5}'.format(-5/2, 18/4))

print(-19//6, 19/-6)
print(list(map(list,zip(*[[1,  2,  3],  [4,  5,  6]]))))

import re
x  =  'a234b123c'
print(re.split('\d+', x))

def F(n):
    if n > 0:
        print(n, end= ' ') 
        F(n-1)
        print(n, end = '\n') 
print(F(3))

print(sorted([2,1,13, 1, 124, 43, 109], key=lambda x: len(str(x))))

def demo(a, b, c): 
    print(a+c, a+b, b+c)
demo(*(1,), **{'c':2, 'b':3})

def F(n):
    if n%2: 
        n=n**2
    else:
        n=n+1 
    return n
print([F(n) for n in [-2, 5, 6, -9, 10] if n>0])

# def Demo(): 
#     try:
#         L = ["We", "Love", "HFUT"] 
#         index = eval(input("input data:")) 
#         print(L[index])
#     except IndexError:
#         print("Index out of range!") 
#     except TypeError:
#         print("TypeError!") 
#     else:
#         print("No exception!") 
#     finally:
#         print("End of Demo")  
# Demo()

x = (5 for i in range(10))
print(type(x))
print(list(x))
print(list(x))

print({2, 4, 3} == {2,3, 4})