# -*- coding utf-8 -*-
# matplotlib demo

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
# 解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

plt.figure(figsize=(6, 4), facecolor='y')

plt.title("plot演示")

plt.plot([1, 2, 3, 4], [4, 5, 6, 7])
plt.plot([1, 2, 3, 4], [1, 4, 9, 16])

plt.legend(['温度变化', "浓度变化"])

plt.show()
