class Animal(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def eat(self):
        print("eat~~")
    def sleep(self):
        print("sleep~~")
    def call(self):
        print(self.name, "call~~")

class Dog(Animal):
    def __init__(self, name, age, sex):
        super(Dog, self).__init__(name, age)
        self.sex = sex
    
    def call(self):
       print(self.name, '会“汪汪”叫')

    def __str__(self):
        return f'{self.name}，今年{self.age}岁了，我会汪汪叫...'

    # def call(self):
    #     print('汪汪叫...')
    # pass
class Cat(Animal):
    def __init__(self, name, age, sex):
        super(Cat, self).__init__(name, age)
        self.sex = sex

    def call(self):
       print(self.name, '会“喵喵”叫')

    def __str__(self):
        return f'{self.name}，今年{self.age}岁了，我会喵喵叫...'

    # def call(self):
    #     print("喵喵叫...")
    # pass
def do(all):
    all.call()
z = Animal("黑子", 5)
x = Dog("小狗",6, "公")
# print(x.__str__())
y = Cat("小猫", 3, "母")
# print(y.__str__())
print(x.sex)
for i in (x,y,z):
    do(i)