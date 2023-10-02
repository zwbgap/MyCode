# 封装一个函数，生成指定位数的验证码
def generate_code(num):
    """generate_code方法主要用于生成指定位数的验证码,传入int类型num参数,其返回结果为生成的指定验证码"""
    import random
    str1 = "0123456789abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    code = ""
    for i in range(num):
        # 从字符串str1中抽取num个参数
        index = random.randint(0,len(str1)-1)
        code += str1[index]
    return code
# help(generate_code)

print(generate_code(6))

fn1 = lambda a: a
print(fn1('hello world'))
fn1 = lambda a, b, c=100: a + b + c
print(fn1(10, 20))
fn1 = lambda *args: args
print(fn1(10, 20, 30)) 
fn1 = lambda **kwargs: kwargs
print(fn1(name='python', age=20))
