"""
编程设计一个基类汽车类 Vehicle，包含最大速度 MaxSpeed，weight 两个实例私
有属性；设计一个派生子类自行车（Bicycle）类，增加 1 个实例私有属性高度（height）
和 1 个成员函数 SetMaxSpeed 实现给父类的实例属性 MaxSpeed 的赋值。
"""


class Vehicle(object):
    def __init__(self, MaxSpeed, weight):
        self.__MaxSpeed = MaxSpeed
        self.__weight = weight

    @property
    def __set(self, M):
        self.__MaxSpeed = M
    def __get(self):
        return self.__MaxSpeed

    def show(self):
        print(f'MaxSpeed: {self.__MaxSpeed}')
        print(f'weight: {self.__weight}')


class Bicycle(Vehicle):
    def __init__(self, MaxSpeed, weight, height):
        super().__init__(MaxSpeed, weight)
        self.__set(height)

    def SetMaxSpeed(self, speed):
        Vehicle.__set = speed
        print(f'The MaxSpeed of Vehicle is set: {Vehicle.__set}')

    def __get(self):
        return self.__height

    def __set(self, h):
        self.__height = h

    def __del(self):
        del self.__height

    height = property(__get, __set, __del)  # height属性为可读可删可修改

    def show(self):
        print(f'The height of Bycycle is: {self.__height}')


v = Vehicle(60, 30)
v.show()
b = Bicycle(10, 4, 0.7)
b.SetMaxSpeed(80)

b.show()
print("set height:")
b.height = 1
b.show()
