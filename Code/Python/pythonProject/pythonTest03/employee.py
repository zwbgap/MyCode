"""
编程设计一个雇员基类 Employee，包括姓名，编号，月薪三个实例属性，月薪计 
算 pay()和信息显示 show()两个函数成员；派生两个子类 manager 类和 salesman 类，重 
载相应的 2 个函数成员。
"""


class Employee:
    def __init__(self, Name, Number, Salary):
        self.name = Name
        self.number = Number
        self.salary = Salary

    def pay(self):  # 月薪的计算
        print(f'The salary of employee is :$ {self.salary}')

    def show(self):  # 其他信息的展示
        print(f'The name of employee is : {self.name}')
        print(f'The number of employee is : {self.number}')


class Manager(Employee):
    def pay(self):
        print(f'The salary of Manager is :$ {self.salary}')

    def show(self):
        print(f'The name of Manager is : {self.name}')
        print(f'The number of Manager is : {self.number}')


class Salesman(Employee):
    def pay(self):
        print(f'The salary of Salesman  is :$ {self.salary}')

    def show(self):
        print(f'The name of Salesman is : {self.name}')
        print(f'The number of Salesman is : {self.number}')


print("Please init the number of employees(integer:1,2,3...)")
while int(input()) > 0:
    name = input('Name :  ')
    number = input('number: ')
    salary = input('salary: ')
    # 实例化对象
    emp = Employee(name, number, salary)
    # employee的相关信息展示
    emp.show()
    emp.pay()
