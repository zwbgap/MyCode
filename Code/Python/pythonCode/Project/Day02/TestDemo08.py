class Person():
    
    # 定义初始化功能的函数
    def __init__(self, name, age, address):
        # 添加实例属性
        self.name = name
        self.age = age
        self.address = address
	
    def print_info(self):
        # 类里面调用实例属性
        print(f'姓名：{self.name}, 年龄：{self.age}，地址：{self.address}')
        
p1 = Person('老王', 18, '北京')
p1.print_info()

p2 = Person('老李', 20, '深圳')
p2.print_info()


class Person():
    
    # 定义初始化功能的函数
    def __init__(self, name, age, address):
        # 添加实例属性
        self.name = name
        self.age = age
        self.address = address
	
    def __str__(self):
        """ 返回一个对象的描述信息 """
        return f'姓名：{self.name}，年龄：{self.age}，地址：{self.address}'
    	
        
p1 = Person('老王', 18, '北京')
print(p1)


class Person():
    
    # 定义初始化功能的函数
    def __init__(self, name, age, address):
        # 添加实例属性
        self.name = name
        self.age = age
        self.address = address
    
    def __del__(self):
        print(f'{self}对象已经被删除')
        
p1 = Person('老王', 18, '北京')

# <__main__.Person object at 0x101af8f90>对象已经被删除
del p1
