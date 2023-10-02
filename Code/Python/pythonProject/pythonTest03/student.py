"""
编程设计学生信息类，实例属性包括：学号、姓名、性别，年龄、n 门课程成绩，
要求：
1)   利用文件读取，创建一个包含  n 个学生的班级;
2)   n 门课程成绩利用字典存储，支持成绩录入、修改;
3) 求解每个学生的三门成绩的平均值，及其平均值排名。并 按照成绩平均成绩排
名正序输出功能：学号、姓名、性别、年龄，三门课程成绩，三门课程平均值，排
名。
"""
import re


class student(object):
    def __init__(self, ID='', NAME='', GENDER='', CLASS='', GRADES=dict()):
        self.ID = ID
        self.NAME = NAME
        self.GENDER = GENDER
        self.CLASS = CLASS
        self.GRADES = GRADES

    @classmethod
    def create_class_from_file(cls, filename):
        reclass = []  # 返回的对象数组
        # 读取文件
        with open(filename, encoding='utf8') as file:
            lines = file.readlines()
            # 逐行对象遍历
            for line in lines:
                line = line.strip('\n')  # strip() 方法用于移除字符串头尾指定的字符（默认为空格或换行符）或字符序列。
                items = line.split(' ')
                # 初始化各属性
                ID = 'None'
                NAME = 'None'
                GENDER = 'None'
                CLASS = 'None'
                GRADES = {}

                def not_set(attribute):
                    if attribute == 'None':
                        return True
                    else:
                        # print("属性", attribute, "在", line, "中被重复设置，请检查是否出错")
                        return False

                for i in items:
                    # 成绩
                    if ':' in i:
                        item = i.split(':')
                        GRADES[item[0]] = item[1]
                    # 性别
                    elif i in ['男', '女'] and not_set(GENDER):
                        GENDER = i
                    # 学号，纯数字
                    elif re.search('^[\d]+$', i) and not_set(ID):
                        ID = i
                    # 班级 数字+班
                    elif re.search('^[\d]+[班]$', i) and not_set(CLASS):
                        CLASS = i
                    elif not_set(NAME):
                        NAME = i
                reclass.append(student(ID, NAME, GENDER, CLASS, GRADES))
        return reclass

    def add_grades(self, dic):
        self.GRADES.update(dic)
        print("成绩导入")

    def modify_grades(self, key, value):
        if key in self.GRADES.keys():
            self.GRADES[key] = value
            print('修改', self.NAME, '的', key, '为', value)
        else:
            self.GRADES[key] = value
            print('未在', self.NAME, '中找到科目', key, ',已添加为:', value)

    def delete_grades(self, key):
        if key in self.GRADES.keys():
            print('删除:', key)
            self.GRADES.pop(key)
        else:
            print('未在', self.NAME, '中找到科目', key)

    def average_grades(self):
        scores = self.GRADES.values()
        Sum = 0
        for i in scores:
            Sum += float(i)
        average = Sum / len(scores)
        return average

    @classmethod  # 不需要实例化，直接通过类.方法名进行调用
    def sort(cls, students):
        stu = sorted(students, key=lambda x: x.average_grades(), reverse=True)
        n = 1
        for i in stu:
            print(i.ID, i.NAME, i.GENDER, i.GRADES, i.average_grades(), n)
            n += 1


alist = student.create_class_from_file('计科212班.txt')
for i in alist:
    print(i.ID, i.NAME, i.GENDER, i.CLASS, i.GRADES)
new_grades = {"线代": 98, "大物": 100}
alist[0].add_grades(new_grades)
print(alist[0].GRADES)
alist[0].modify_grades("线代", 90)
print(alist[0].GRADES)
alist[0].delete_grades("线代")
print(alist[0].GRADES)
student.sort(alist)











"""
20202101 张三 男 1班 {'高数':'89','英语':‘25’, '计算机':'77'}
20202102 李四 女 1班 {'高数':'88','英语':‘78’, '计算机':'76'}
20202105 王五 男 1班 {'高数':'87','英语':‘34’, '计算机':'67'}
20202104 赵六 女 1班 {'高数':'86','英语':‘89’, '计算机':'66'}

"""






