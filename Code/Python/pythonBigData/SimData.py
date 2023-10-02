# -*- coding: utf-8 -*-
"""
This program generate  simdata
"""
from faker import Faker
import random

scorels = ['A+','A','A-','B+','B','B-','C+','C','C-','D+','D','D-','E']
nameMls = ['新媒体','城市地下空间','新能源','食品','环境','计算机','电信科','机械工程','土木工程','自动化','物流管理','法学','英语','广告','经济','化工']
fdata = Faker(locale= "zh_CN")
simData = []
idbase = 6000
for i in range(2100):   
    item = []
    item.append(fdata.name())
    st = fdata.ssn()
    st = st[0:6] + 'XXXXXXXX' +st[14:]
    item.append(st)
    item.append("202321"+str(idbase))
    item.append(random.choice(nameMls) \
        + random.choice(["23-1班",'23-2班','23-3班']))
    item.append(str(random.randint(45, 100)))
    item.append(str(random.randint(25, 100)))
    item.append(str(random.randint(15, 100)))
    item.append(str(random.randint(35, 100)))
    item.append(random.choice(scorels))
    idbase += 1
    simData.append(item)

print(simData[:20])

f = open(r"e:\tmp.csv", "w")#, encoding='utf-8')
f.write("姓名,身份证号,学号,专业班级,C1,C2,C3,C4,C5\n")
for item in simData:
    string = ",".join(item)
    f.write(string)
    print(string)
    f.write("\n")

f.close()
