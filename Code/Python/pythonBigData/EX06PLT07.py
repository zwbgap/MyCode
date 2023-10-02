#-*- coding utf-8 -*-
#Demo of Probability histogram

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False


y1 = np.random.normal(0,1,10000)
y2 = np.random.uniform(0,1,10000)
y1_pdf = pd.Series(y1)

plt.subplot(511)
plt.xlim(-4,4)
plt.hist(y1,color = 'r',alpha=0.73,bins=50)
plt.title("正态分布直方图",fontsize=16)
plt.xlabel("范围")
plt.ylabel("频率")

plt.subplot(513)
plt.xlim(-4,4)
y1_pdf.plot(kind = 'kde', style = 'g--')
plt.title("概率密度",fontsize=16)
plt.xlabel("范围")
plt.ylabel("频率")

plt.subplot(515)
plt.xlim(-0.1,1.1)
plt.hist(y2,color = 'g',alpha=0.73,bins=50)
plt.title("均匀分布直方图",fontsize=16)
plt.xlabel("范围")
plt.ylabel("频率")

plt.grid(True)

plt.show()