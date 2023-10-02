# 定义爬取豆瓣网信息函数
import csv
import requests
from bs4 import BeautifulSoup

#从豆瓣网爬取相关信息
def parse_html(book):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
    }
    response = requests.get(f'https://www.douban.com/search?q=' + book, headers=headers)
    # response = requests.get(f'https://book.douban.com/top250?start={num}', headers=headers)
    soup = BeautifulSoup(response.text, 'lxml')
    # print(soup)

    # 类型和名称
    all_Type = soup.find_all('h3')
    book_names = [Type.get_text() for Type in all_Type]
    leixing = []
    mingcheng = []
    for piece in book_names:
        if "小组" in piece:
            continue
        elif "日记" in piece:
            continue
        else:  # 首先去除爬取到的多余信息
            piece = piece.strip().replace(' ', '')
            piece = piece.strip().replace('[', '')
            piece = piece.strip().replace('可播放', '')
            piece = piece.strip().replace('可试读', '')
            piece = piece.strip().replace('有电子版', '')
            piece = piece.strip().replace('\n', '')
            piece = piece.strip().replace('\xa0', '')
            str1 = piece.split(']')
            if book in str1[0]:
                continue
            else:
                leixing.append(str1[0])
                mingcheng.append(str1[1])
            # for i in str1:
            # print(i)
        # print(len(leixing))
        # print(mingcheng)

        # 出版年份ok
    all_year = soup.find_all('span', class_='subject-cast')
    nianfen = []
    book_years = [year.get_text() for year in all_year]
    for piece in book_years:
        str1 = piece.split(' ')
        try:
            nianfen.append(int(str1[-1]))  # 在获得数据中摘取出版年份
        except:  # 抛出异常，排除没有出版年份（即对应位置数据不能转换成int型数据）的情况
            nianfen.append(0)
    # print(len(nianfen))

    # 评价人数ok
    all_people = soup.find_all('span', class_='')
    book_people = [people.get_text() for people in all_people]
    renshu = []
    i = 0
    for piece in book_people:
        if '[' not in piece:
            i += 1
        else:
            break
    book_people = book_people[i::]  # 摘除开头多余的信息
    for piece in book_people:
        if '日记' in piece:
            continue
        elif '小组' in piece:
            continue
            # print(piece)
        elif '人评价' in piece:  # 摘取含有评价人数的元素
            piece = piece.strip('(').strip(')')
            piece = piece.strip("人评价")  # 去除字符串中多余指定字符
            renshu.append(int(piece))
        elif "(" in piece:  # 对于“暂未上映”或者“尚无评价”的数据，将评价人数赋为0
            renshu.append(0)
            # else:
            # renshu.append(0)
        # print(type(book_people))
        # print(len(renshu))
        # print(renshu)

        # 评分ok
    all_mark = soup.find_all('span', class_='rating_nums')
    book_rates = [mark.get_text() for mark in all_mark]
    # print(len(book_rates))
    pingfen = []
    for i in range(len(mingcheng)):  # 不能用len(book_rates)，某些无评分的数据未导入，book_rates长度比其他列表短，会造成信息错乱
        if renshu[i] == 0:
            pingfen.append(float(0))  # 对于无评分的数据将评分补成0
            book_rates.insert(i, '0')  #
        else:
            pingfen.append(float(book_rates[i]))
    # print(len(pingfen))
    # print(len(mingcheng))
    # print(pingfen)

    content = []
    content = [leixing, mingcheng, nianfen, renshu, pingfen]
    return content


# csv 写入
def write_(book, content):
    # Type.append('type')
    # Name.append('name')
    content[0].insert(0, "类型")
    content[1].insert(0, "名称")
    content[2].insert(0, "出版年份")
    content[3].insert(0, "评价人数")
    content[4].insert(0, "评分")
    file1 = open(book + '.csv', 'a+', newline='')
    # a+:打开一个文件用于读写。如果该文件已存在，文件指针将会放在文件的结尾。文件打开时会是追加模式。如果该文件不存在，创建新文件用于读写。
    # 设定写入模式
    csv_write = csv.writer(file1, dialect='excel')
    # 写入具体内容
    # dataframe1 = pd.DataFrame({'Type':Type,'Name':Name})

    for val in zip(content[0], content[1], content[2], content[3], content[4]):
        csv_write.writerow(val)

    file1.close()
    print("write over")


# 从豆瓣网上爬取四大名著相关产品的数据
if __name__ == '__main__':
    print('begin')
    data1 = parse_html("红楼梦")
    data2 = parse_html("水浒传")
    data3 = parse_html("三国演义")
    data4 = parse_html("西游记")
    print(data1)
    print(data2)
    print(data3)
    print(data4)
    print('end')


# 将数据写入.csv文件
# write_("红楼梦", data1)
# write_("水浒传", data2)
# write_("三国演义", data3)
# write_("西游记", data4)




