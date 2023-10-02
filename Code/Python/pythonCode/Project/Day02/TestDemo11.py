class Girl():
    def __init__(self):
        self.name = '小美'
        self.__age = 18
        
    def get_age(self):
        return self.__age
    
    def set_age(self, age):
        self.__age = age


girl = Girl()
girl.set_age(19)
print(girl.get_age())

class Tool(object):
    # 定义类属性，用于记录创建了多少个工具对象
    count = 0
    
    @classmethod
    def show_tools_count(cls):
        print(f'工具对象的数量：{cls.count}')
    
    def __init__(self, name):
        self.name = name
        # 针对类属性做一个计数+1操作
        Tool.count += 1
    @staticmethod
    def menu():
      print('------')
      print('开始[1]')
      print('暂停[2]')
      print('退出[3]')

        
tool1 = Tool('斧头')
tool2 = Tool('榔头')
tool3 = Tool('铁锹')

# 输出工具对象的总数
print(Tool.count)
Tool.show_tools_count()
Tool.menu()