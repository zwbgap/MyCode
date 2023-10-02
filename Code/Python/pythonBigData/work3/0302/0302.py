import requests
from bs4 import BeautifulSoup as bs
import jieba
import matplotlib.pyplot as plt
import wordcloud

str_data = []
for i in range(1, 9):
    response = requests.get("http://xc.hfut.edu.cn/1954/list{0}.htm".format(i))
    response.encoding = 'utf-8'
    str_data.append(response.text)
div_news = []
for page in str_data:
    soup = bs(page, 'html.parser')
    div_news.append(soup.findAll('span', class_='news_title', attrs='title'))  #每页十四条

news_title_100 = []
for i in range(len(div_news) - 1):
    for j in range(0, len(div_news[0])):
        news_title_100.append(div_news[i][j])
news_title_100.append(div_news[len(div_news) - 1][0])
news_title_100.append(div_news[len(div_news) - 1][1])
# print(type(news_title_100[0]))   #<class 'bs4.element.Tag'>
news_title_100_list = []  #标题列表
for item in news_title_100:
    news_title_100_list.append(item.text)
print(news_title_100_list)
str_list = ''.join(news_title_100_list)
text_cut = jieba.lcut(str_list)
print(text_cut)
text_cut = '/'.join(text_cut)

myImg = plt.imread(r'D:\\pythonBigData\\work3\\0302\\xc_1.jpg')
myWordCloud = wordcloud.WordCloud(font_path="simfang.ttf",max_font_size=500,max_words = 2000,mask = myImg, collocations=False,background_color='white')
myWordCloud.generate(text_cut)

myImg_color = wordcloud.ImageColorGenerator(myImg)
myWordCloud.recolor(color_func=myImg_color)

myWordCloud.to_file(r"D:\\pythonBigData\\work3\\0302\\hfut_XC.png")
plt.figure("词云图", figsize=(8, 6))
plt.imshow(myWordCloud)
plt.axis("off")
plt.show()