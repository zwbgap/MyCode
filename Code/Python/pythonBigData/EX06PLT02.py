# -*- coding utf-8 -*-
# Demo subplt

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
# 解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

x = np.arange(-10, 11)

plt.subplot(221)

plt.plot(x, x)

plt.subplot(222)
plt.title("抛物线")
plt.plot(x, x * x)

plt.subplot(212)
plt.plot(x, np.log(np.abs(x)))

plt.show()
