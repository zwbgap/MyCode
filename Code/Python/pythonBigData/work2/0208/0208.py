"""
通过文件读取群文件中的price2016.csv的数据,以标题为建,数据为值生成
高维json数据(典列表),然后通过标准json模块转储为price2016.json文件 
"""
import json

if __name__ == "__main__":

    fIn = open("price2016.csv", "r")
    ls = []
    for line in fIn:
        line = line.replace("\n", "")
        ls.append(line.split(','))
    fIn.close()

    fOut = open("price2016.json", "w")

    for i in range(1, len(ls)):
        ls[i] = dict(zip(ls[0], ls[i]))

    json.dump(ls[1:], fOut, ensure_ascii=False, indent=4)
    fOut.close()