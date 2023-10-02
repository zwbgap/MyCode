# -*- coding utf-8 -*-
# matplotlib demo

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 设置字体为楷体
plt.rcParams['font.sans-serif'] = ['KaiTi']
# 解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

plt.figure(figsize=(8, 6), facecolor='y')

y = np.random.uniform(5, 8, 12)
x = np.arange(1, 13)

plt.plot(x, y)

plt.xlim(0, 13)
plt.ylim(0, 12)

plt.title("12个月的销售额", fontsize=20)

plt.xlabel('月份', fontsize=16)
plt.ylabel('销售额(元)', fontsize=16)

plt.grid(linestyle='--', color='r', alpha=0.5)
m = np.random.uniform(4, 7, 12)
n = np.random.uniform(4, 8, 12)

plt.plot(x, m, 'r-*', alpha=0.7)
plt.plot(x, n, 'g:o')

plt.legend(['1分公司', '2分公司', '3分公司'])
plt.show()
