"""
词频分析
⑴自己从网上搜索下载若干篇中文或英文文本文件；
⑵编写Python程序代码，对下载的文档进行词频统计(应去除无关的构词，可增添新创的构词)；
⑶根据词频统计的结果构建自己的分析模型，分析这篇文档的内涵(如政府工作报告中出现的那些最频繁的词与国家治理发展的关系)；
⑷形成词频对应的词云，背景图像自选。
"""

import jieba
from wordcloud import WordCloud


def wordcloudCh(filename):
    print("{0}词频分析".format(filename[:-4]))
    with open(filename, 'r', encoding='utf-8') as f:
        txt = f.read()
    words = jieba.lcut(txt)

    dic = {}

    exp = {'的', '了', '“', '”', '在', '对', '。', '!', '?', '」', '「', '…', '<', '>', ',', '和'}
    keys = set(words) - exp

    for i in keys:
        if len(i) > 1:  # 最少两个字组成一个词
            dic[i] = words.count(i)

    word = list(dic.items())
    word.sort(key=lambda x: x[1], reverse=True)
    for i in range(20):  # 取前二十个高频词
        print(word[i])

    result = " ".join(words)
    wc = WordCloud(background_color='white', font_path="simfang.ttf",
                   width=800, height=600, scale=5, stopwords=exp)

    wc.generate(result)
    wc.to_file(r"{0}.png".format(filename[:-4]))


if __name__ == "__main__":
    wordcloudCh("乡村振兴.txt")
    wordcloudCh("改革开放.txt")
