class Student():
    def __init__(self, name, score):
        self.name = name
        self.score = score
        
    def print_grade(self):
        if self.score >= 90:
            print(f'{self.name}，{self.score}分，成绩优秀')
        elif self.score >= 80:
            print(f'{self.name}，{self.score}分，成绩良好')
        elif self.score >= 70:
            print(f'{self.name}，{self.score}分，成绩中等')
        elif self.score >= 60:
            print(f'{self.name}，{self.score}分，成绩及格')
            
p1 = Student('Tom', 80)
p1.print_grade()

p2 = Student('Rose', 99)
p2.print_grade()


class Person():
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
    
    def __str__(self):
        return f'姓名：{self.name}，体重：{self.weight}'
    
    def run(self):
        print(f'{self.name}爱跑步，每次跑步可以减掉0.5公斤')
        self.weight -= 0.5
        
    def eat(self):
        print(f'{self.name}是一个小吃货，每次吃东西体重都会增长1公斤，太难了')
        self.weight += 1
        

xm = Person('小明',75.0)
print(xm)
for i in range(5):
    xm.run()
xm.eat()
print(xm)
