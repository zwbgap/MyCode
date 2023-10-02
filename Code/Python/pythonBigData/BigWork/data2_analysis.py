# 分别统计四本书中出现次数最多的五十个词组并绘制词云
import wordcloud
import matplotlib.pyplot as plt


def maxword(book, path):
    exclude_str = "，。！？、（）【】<>《》=：+-*—“”‘’… ；\n了你我她他的\u3000不一来人这儿是下此着个子下上曰之有"  # 除去标点符号和无用字符
    f = open(path, encoding='gb18030')
    content = []

    for line in f:  # 将每个词组存储到列表中
        # line = list(line)
        for i in range(len(line) - 1):  # 除去标点符号和无用字符
            if line[i] not in exclude_str:
                if line[i + 1] not in exclude_str:
                    content.append(line[i] + line[i + 1])

    count = {}  # 统计每个字出现的数量
    for character in content:
        count.setdefault(character, 0)  # 如果键不存在于字典中，将会添加键并将值设为默认值
        count[character] = count[character] + 1
    # 排序
    # x[1]是按字频排序，x[0]则是按字排序
    lstWords = sorted(count.items(), key=lambda x: x[1], reverse=True)
    print(book + "中出现频率最高的一百个词组为：")
    print('字符\t字频 \t ' * 5)
    n = 0
    text = []
    for e in lstWords[:100]:
        if n % 5 == 0 and n != 0:
            print()
        n = n + 1
        text.append(e[0])
        print('%s\t%d' % e, end=' \t ')
    print()
    text = '/'.join(text)
    myImg = plt.imread(r'D:\\pythonBigData\\BigWork\\hfut_xc.jpg')
    myWordCloud = wordcloud.WordCloud(font_path="simfang.ttf", max_font_size=500, max_words=2000, mask=myImg,
                                      collocations=False, background_color='white')
    myWordCloud.generate(text)

    myImg_color = wordcloud.ImageColorGenerator(myImg)
    myWordCloud.recolor(color_func=myImg_color)

    myWordCloud.to_file(fr'{book}.png')
    plt.figure("词云图", figsize=(8, 6))
    plt.imshow(myWordCloud)
    plt.axis("off")
    plt.show()
    f.close()


maxword("《红楼梦》", r"D红楼梦.txt")
maxword("《西游记》", r"西游记.txt")
maxword("《水浒传》", r"水浒传.txt")
maxword("《三国演义》", r"三国演义.txt")
