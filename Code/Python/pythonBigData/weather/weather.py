import requests
from bs4 import BeautifulSoup


def getHTMLtext(url):
    """请求获取网页内容"""
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        print("successfully requests")
        return r.text
    except:
        print("successfully")
        return " "


def get_content(html):
    """处理得到有用信息保存数据文件"""
    final = []  # 初始化列表保存数据
    bs = BeautifulSoup(html, "html.parser")  # 创建BeautifulSoup对象
    body = bs.body
    data = body.find('div', {'id': '7d'})  # 找到div标签并且id=7d
    # 下面爬取当天数据
    data2 = body.find_all('div', {'class': 'left-div'})
    text = data2[20].find('script').string
