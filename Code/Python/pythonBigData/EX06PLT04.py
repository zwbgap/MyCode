#-*- coding utf-8 -*-
#Demo of bar

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

plt.figure(figsize=(8, 6))

y = np.random.uniform(5,8,12)
x = np.arange(1,13)
plt.bar(x,y)

plt.xlim(0,13)
plt.ylim(0,12)

plt.title("12个月的销售额",fontsize=20)
plt.xlabel('月份',fontsize=16)
plt.ylabel('销售额(千元)',fontsize=16)

plt.grid(linestyle='--',color='c',alpha=0.5)

plt.xticks(list(x))

for a,b in zip(x,y):
    plt.text(a-0.3,b+0.1,'%.1f'%b)
plt.show()
