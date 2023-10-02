#-*- coding utf-8 -*-
#matplotlib demo

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False


fig,axes = plt.subplots(2,1,figsize = (10,6))
df = pd.DataFrame(np.random.rand(10,5),columns=['A','B','C','D','E'])
color = dict(boxes  = 'DarkGreen',whiskers = 'DarkOrange',medians = 'DarkBlue',caps ='Gray')
# 箱型图着色
# boxes 箱线
# whiskers 分为数于error bar横线之间的竖线的颜色
# medians 中位线的颜色
# caps error bar 横线的颜色
df.plot.box(ylim = [0,1.2],   # y轴刻度范围
            grid = True,
            color  = color,   # color 样式填充
            ax = axes[0])

df.plot.box(vert = False,     # 是否垂直 默认true
            positions=[1,4,5,6,8],    # 箱型图占位 相当于箱体之间的间隔
            ax = axes[1],
            grid = True,
            color = color)

plt.grid(linestyle='--')
plt.show()
