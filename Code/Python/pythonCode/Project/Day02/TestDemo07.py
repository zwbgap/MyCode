from unicodedata import name


class Person():
    name = '张扬'
    age = 18
    address = '安徽宣城合肥工业大学'
    def print_info(self):
        # 类里面获取实例属性
        print(f'姓名：{self.name}')
        print(f'年龄：{self.age}')
        print(f'地址：{self.address}')

    def eat(self):
        print('我喜欢吃零食')
    def drink(self):
        print('我喜欢喝果汁')

p1 = Person()

# print(p1)
p1.print_info()
p1.drink()
p1.eat()