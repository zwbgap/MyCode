#-*- coding utf-8 -*-
#Demo of Rada fig.

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

labels = np.array(['艺术A','调研I','实际R','常规C','企业E','社会S'])  #数据个数
dataLenth = 6    #数据
data = np.array([1,4,3,6,4,8])

angles = np.linspace(0, 2*np.pi, dataLenth, endpoint=False)

data = np.concatenate((data, [data[0]])) # 闭合
angles = np.concatenate((angles, [angles[0]])) # 闭合

plt.polar(angles,data,'yo-',linewidth=1)   #绘制雷达图
plt.thetagrids(angles[1:]*180/np.pi,labels)    #设置角度网络标签
plt.fill(angles,data,facecolor='r',alpha= 0.2)  #填充内容颜色
plt.title("雷达图",fontsize=16)   #设置图标题
plt.grid(True)
plt.show()