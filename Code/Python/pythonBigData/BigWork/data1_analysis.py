# 定义函数，读取csv文件并将信息按列分离
import matplotlib.pyplot as plt
from pylab import mpl  # 字体
import csv
def open_data(book):
    mxdPath = book + r".csv"
    file = open(mxdPath)
    content = csv.reader(file)  ##reader(f)读取文件中的一行，read()只能读取一个字符
    data = []
    Type = []
    Name = []
    Year = []
    People = []
    Mark = []
    for piece in content:
        data.append(piece)
    # print(data)
    for piece in data[1::]:  # 第一行为各列名称，所以从第二行开始截取，即data[1]
        Type.append(piece[0])
        Name.append(piece[1])
        Year.append(piece[2])
        People.append(piece[3])
        Mark.append(piece[4])
    # print(content)
    file.close()
    content = [Type, Name, Year, People, Mark]
    return content


# 打开四个表格
content1 = open_data('红楼梦')
print(content1[0])
content2 = open_data('西游记')
print(content2[0])
content3 = open_data('水浒传')
print(content3[0])
content4 = open_data('三国演义')
print(content4[0])


# 定义函数，对于爬到的产品类型进行分析
def ana_type(book, Type):
    type_dict = {}

    for data in Type:  # 统计各个类型的产品数量，不同类型作为字典的key
        if data not in type_dict.keys():  # 如果该key不存在，则将value值初始化为1
            type_dict[data] = 1
        else:  # 如果该key存在，则将value值加1
            type_dict[data] += 1

            # print (type_dict)
    num = []
    typename = []
    explode = []
    print(type_dict)
    for key, value in type_dict.items():
        typename.append(key)
        num.append(value)
    for name in typename:
        explode.append(0)
    explode = tuple(explode)
    # for key in type_dict
    drawpie(book, typename, num, explode)
    return num


# 定义函数，绘制饼状图
# 设置字体
def drawpie(book, name, num, explode):  # 画饼状图
    mpl.rcParams['font.sans-serif'] = ['SimHei']
    plt.title("豆瓣网《" + book + "》相关产品种类分布情况")
    sizes = num
    colors = 'lightgreen', 'gold', 'lightskyblue', 'lightcoral'
    # explode=0,0,0
    # print(type(explode))
    plt.pie(sizes, explode=explode, labels=name,
            colors=colors, autopct='%1.1f%%', shadow=True, startangle=50)
    plt.axis('equal')
    plt.savefig(fr'《{book}》相关产品种类分布情况饼状图.png', bbox_inches="tight")
    plt.show()


# 分析四大名著相关产品的类型分布，并绘制对应的饼状图,类型为表格中的第一列(content[0])
num1 = ana_type("红楼梦", content1[0])
num2 = ana_type("西游记", content2[0])
num3 = ana_type("水浒传", content3[0])
num4 = ana_type("三国演义", content4[0])


# 定义函数，对于爬到的产品出版年份进行分析
def ana_year(book, Year):
    num = [0, 0, 0, 0, 0]
    for data in Year:
        data = int(data)
        if data < 1979:
            num[0] += 1
        elif data < 1990:
            num[1] += 1
        elif data < 2000:
            num[2] += 1
        elif data < 2010:
            num[3] += 1
        else:
            num[4] += 1
    # print (type_dict)
    print(num)
    drawyear(book, num)


# 定义函数，绘制出版年份柱状图
# 解决中文显示问题
def drawyear(book, count):  # 画折线图
    mpl.rcParams['font.sans-serif'] = ['SimHei']
    plt.title("《" + book + "》相关产品出版年份统计")
    name_list = ['1979年以前', '1979-1990', '1990-2000', '2000-2010', '2010年之后']
    plt.xlabel("时间")
    plt.ylabel("新出版产品数量")

    plt.plot(name_list, count)

    # autolabel(rect)
    plt.savefig(fr'《{book}》相关产品出版年份统计折线图.png', bbox_inches="tight")
    plt.show()
    # print(count)
    return count


# 分析出版年份，对应表格中的第三列(content[2])
ana_year("红楼梦", content1[2])
ana_year("西游记", content2[2])
ana_year("水浒传", content3[2])
ana_year("三国演义", content4[2])


# 定义函数，分析四大名著的评价人数和得分情况
def ana_mark(people, mark):
    sum_ = [0, 0, 0, 0]
    mark_ = [0, 0, 0, 0]
    for i in range(4):
        for data in people[i]:
            if data == 0:
                continue
            else:
                sum_[i] += int(data)
        for data in mark[i]:
            if data == 0:
                continue
            else:
                mark_[i] += float(data)
        sum_[i] = sum_[i] / len(people[i])
        mark_[i] = mark_[i] / len(mark[i])
    print(sum_)
    drawmark(mark_)
    draw_mark(sum_, mark_)


# 定义函数，画四大名著得分比较的柱状图
def autolabel(rects):  # 在柱状图上显示数量坐标
    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x() + 0.14, 1.03 * height, '%s' % height)


def drawmark(mark):
    mpl.rcParams['font.sans-serif'] = ['SimHei']

    plt.title("四大名著相关出版物平均得分统计")
    name_list = ['红楼梦', '西游记', '水浒传', '三国演义']
    plt.xlabel("书名")
    plt.ylabel("得分")

    plt.xticks((0, 1, 2, 3), ('红楼梦', '西游记', '水浒传', '三国演义'))
    # print(type(mark[0]))

    # plt.bar(x = (0,1,2,3),height = distance,width = 0.35,align="center")
    # my_y_ticks = np.arange(0, 7, 0.05)
    # plt.yticks(my_y_ticks)
    for i in range(4):
        mark[i] = round(mark[i], 2)  # 将评分保留至小数点后两位
        # print(data)
    print(mark)
    rect = plt.bar(x=(0, 1, 2, 3), height=mark, width=0.35, align="center", color='orange')
    # rect = plt.bar(x = (0,1,2,3,4),height = count,width = 0.35,align="center")
    height = mark
    # print(type(height[0]))
    autolabel(rect)  # 显示柱状图的数值
    plt.savefig(fr'四大名著相关出版物平均得分统计柱状图.png', bbox_inches="tight")
    plt.show()
    # print(count)
    # return count


# 定义函数，绘制并列柱状图，分析评价人数和得分
def autolabel2(rects2):  # 在柱状图上显示数量坐标
    for rect in rects2:
        height = round(rect.get_height(), 2)
        print(height)
        plt.text(rect.get_x() + 0.05, 1.03 * height, '%s' % round(height / 5000, 2))  # 设置显示坐标位置和数值


def draw_mark(sum_, mark_):
    name_list = ['红楼梦', '西游记', '水浒传', '三国演义']
    y_list = sum_
    for i in range(4):
        mark_[i] = round(mark_[i], 2)  # 将评分保留至小数点后两位
        # print(mark_[i])
        mark_[i] = 5000 * mark_[i]
        # print(mark_[i])
    # print(sum_)

    # print(mark_)
    y_list2 = mark_
    # bar_width = 0.3
    # size = 4
    # x = np.random.random(len(x_data))
    x = list(range(len(y_list)))
    total_width, n = 0.8, 2
    width = total_width / n
    # 绘制柱状图

    # 在柱状图上显示具体数值, ha参数控制水平对齐方式, va控制垂直对齐方式
    # for x, y in enumerate(y_data):
    # plt.text(x, y + 100, '%s' % y, ha='center', va='bottom')
    # for x, y in enumerate(y_data2):
    # plt.text(x+bar_width, y + 100, '%s' % y, ha='center', va='top')
    rect = plt.bar(x, y_list, width=width, label='平均评论人数', fc='y')
    for i in range(len(x)):
        x[i] = x[i] + width
    rect2 = plt.bar(x, y_list2, width=width, label='平均得分', tick_label=name_list, fc='r')
    plt.legend()
    # plt.show()
    # 设置标题
    plt.title("豆瓣网四大名著相关评论数和得分情况")
    plt.xlabel("书籍")
    plt.ylabel("数量")
    autolabel2(rect2)
    # plt.legend()
    plt.savefig(fr'豆瓣网四大名著相关评论数和得分情况柱状图.png', bbox_inches="tight")
    plt.show()


# 分析四大名著相关出版物平均得分和评价人数
people = [content1[3], content2[3], content3[3], content4[3]]
mark = [content1[4], content2[4], content3[4], content4[4]]
ana_mark(people, mark)


def ana_typemark(book, type_, num, mark_):  # type_为各类书籍的类型，mark_为得分列表,num为不同类型的产品数量
    type_dict = {}
    for i in range(1, len(type_)):  # 遍历列表中的各个元素
        if type_[i] not in type_dict.keys():  # 如果该key不存在，则将value值初始化为该组数据得分
            type_dict[type_[i]] = float(mark_[i])
        else:  # 如果该key存在，则将value值加1
            type_dict[type_[i]] += float(mark_[i])

    sum_ = []
    typename = []  # 类型名称列表
    average = []  # 各个类型对应的平均分
    explode = []
    for key, value in type_dict.items():
        typename.append(key)
        sum_.append(value)
        explode.append(0)
    i = 0
    for key, value in type_dict.items():
        average.append(value / num[i])
        i += 1
    explode = tuple(explode)
    drawtype(book, typename, average, explode)


# 定义函数，画四大名著不同类型得分比较的柱状图
def drawtype(book, typename, average, explode):
    mpl.rcParams['font.sans-serif'] = ['SimHei']

    plt.title("《" + book + "》不同类型出版物平均得分统计")
    name_list = typename
    plt.xlabel("类型")
    plt.ylabel("平均得分")
    list1 = []
    for i in range(len(typename)):
        list1.append(i)
    list1 = tuple(list1)
    typename = tuple(typename)
    # plt.xticks((0,1,2,3),('红楼梦', '西游记', '水浒传', '三国演义'))
    plt.xticks(list1, typename)  # 参数要求为元组，强制类型转换
    # print(type(mark[0]))

    # plt.bar(x = (0,1,2,3),height = distance,width = 0.35,align="center")
    # my_y_ticks = np.arange(0, 7, 0.05)
    # plt.yticks(my_y_ticks)
    for i in range(len(typename)):
        average[i] = round(average[i], 2)  # 将评分保留至小数点后两位
        # print(data)
    print(average)
    rect = plt.bar(x=list1, height=average, width=0.35, align="center", color='lightblue')
    # rect = plt.bar(x = (0,1,2,3,4),height = count,width = 0.35,align="center")
    height = average
    # print(type(height[0]))
    autolabel(rect)  # 显示柱状图的数值
    plt.savefig(fr'《{book}》不同类型出版物得分情况统计柱状图.png', bbox_inches="tight")
    plt.show()
    # print(count)
    # return count


ana_typemark("红楼梦", content1[0], num1, content1[4])
ana_typemark("西游记", content2[0], num2, content2[4])
ana_typemark("水浒传", content3[0], num3, content3[4])
ana_typemark("三国演义", content4[0], num4, content4[4])
