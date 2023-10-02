def fun():
    return 1, 2

def size(num1, num2):
    return num1+num2,num1-num2, num1*num2,num1/num2

result = fun()
print(result)
print(type(result))

result1 = size(10,2)
print(result1)