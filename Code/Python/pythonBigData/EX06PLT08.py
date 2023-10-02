#-*- coding utf-8 -*-
#Demo of scatter

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

#绘制散点图
x=np.random.rand(30)
y=np.random.rand(30)

plt.subplot(311)
plt.scatter(x,y,s=200,c='b',marker='v',alpha=0.6)
#Mark fmt :   'o' ',' '.' 'x' '+' 'v' '^' '<' '>' 's' 'd' 'p'
plt.title("散点图",fontsize=18)
plt.xlabel("x坐标",fontsize=14)
plt.ylabel("y坐标",fontsize=14)

plt.subplot(313)
s1 = np.random.uniform(60,4000,30)
c1 = np.random.uniform(1,10,30)

plt.scatter(x,y,s = s1,c = c1,marker='o',alpha=0.4)
plt.title("气泡图",fontsize=18)
plt.xlabel("x坐标",fontsize=14)
plt.ylabel("y坐标",fontsize=14)

plt.show()